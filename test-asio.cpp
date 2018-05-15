/*
 * Copyright [2016] <BLIPPAR>
 */

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace std;
//using std::this_thread;

boost::asio::io_service g_ios;
mutex g_stream_mutex;

void func1() {
    boost::asio::io_service ios;
    boost::asio::io_service::work work(ios);
    ios.run();

    cout << "kk" << endl;
}

void func4() {
    boost::asio::io_service ios;
    shared_ptr<boost::asio::io_service::work> work(
        new boost::asio::io_service::work(ios)
    );
    work.reset();
    ios.run();

    cout << "kk" << endl;
}

void func2() {
    boost::asio::io_service ios;
    boost::asio::io_service::work work(ios);
    for (int i = 0; i < 20; i++) {
        ios.poll();
        cout << "c: " << i << endl;
    }
}

void work_thread1() {
    g_stream_mutex.lock();
    cout << "thread start: " << std::this_thread::get_id() << endl;
    g_stream_mutex.unlock();

    g_ios.run();

    g_stream_mutex.lock();
    cout << "thread end: " << std::this_thread::get_id() << endl;
    g_stream_mutex.unlock();
}

void work_thread(shared_ptr<boost::asio::io_service> ios) {
    g_stream_mutex.lock();
    cout << "thread start: " << std::this_thread::get_id() << endl;
    g_stream_mutex.unlock();

    ios->run();

    g_stream_mutex.lock();
    cout << "thread end: " << std::this_thread::get_id() << endl;
    g_stream_mutex.unlock();
}

void func3() {
    shared_ptr<boost::asio::io_service::work> work(
                        new boost::asio::io_service::work(g_ios));
    g_stream_mutex.lock();
    cout << "[" << std::this_thread::get_id() << "] press [return] to exit" << endl;
    g_stream_mutex.unlock();

    boost::thread_group worker_threads;
    for (int i = 0; i < 4; i++) {
        worker_threads.create_thread(work_thread1);
    }

    cin.get();
    g_ios.stop();
    worker_threads.join_all(); 
}

void dispatch(int x) {
    g_stream_mutex.lock();
    cout << "[" << std::this_thread::get_id() << "] " 
         << __FUNCTION__ <<  " x=" << x << endl;
    g_stream_mutex.unlock();
}

void post(int x) {
    g_stream_mutex.lock();
    cout << "[" << std::this_thread::get_id() << "] " 
         << __FUNCTION__ <<  " x=" << x << endl;
    g_stream_mutex.unlock();
}

void run3(shared_ptr<boost::asio::io_service> ios) {
    for (int i = 0; i < 3; i++) {
        ios->dispatch(boost::bind(&dispatch, i*2));
        ios->post(boost::bind(&post, i*2 + 1));
        boost::this_thread::sleep( boost::posix_time::milliseconds( 1000 ) );
    }
}

void func5() {
    shared_ptr<boost::asio::io_service> ios(
                        new boost::asio::io_service);
    shared_ptr<boost::asio::io_service::work> work(
                        new boost::asio::io_service::work(*ios));
    g_stream_mutex.lock();
    cout << "[" << std::this_thread::get_id() << "] the program will exit when all work has done" << endl;
    g_stream_mutex.unlock();

    boost::thread_group worker_threads;
    for (int i = 0; i < 3; i++) {
        worker_threads.create_thread(boost::bind(&work_thread, ios));
    }
    ios->post(boost::bind(&run3, ios));

    work.reset();
    worker_threads.join_all(); 
}

int main(int argc, char *argv[]) {
    //func1();
    //func2();
    //func3();
    //func4();
    func5();

    return 0;
}
