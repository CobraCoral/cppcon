using namespace std;

class MyMutex
{
private:
    pthread_mutex_t _mutex;

public:
    MyMutex()
    {
        pthread_mutex_init(&_mutex, NULL);
    }

    void lock()
    {
        pthread_mutex_lock(&_mutex);
    }

    void unlock()
    {
        pthread_mutex_unlock(&_mutex);
    }
};

int main(int argc, char* argv[])
{
    MyMutex m;
    auto res = test([](MyMutex& m)
    {
        const int LOOP {1000};
        for (int i=0; i<LOOP; ++i)
        {
            m.lock();
            m.unlock();
        }
        return LOOP;
    }, m);
    cout << "Function ran for " << duration_cast<nanoseconds>( res.second ).count()/res.first << " ns " << endl;
}
