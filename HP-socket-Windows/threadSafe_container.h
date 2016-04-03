#include <list>
#include <mutex> 
#include <string>

template<typename T>
class CThreadSafeList
{
public:
	CThreadSafeList() {}
	~CThreadSafeList() 
	{
		if (!list_.empty())
		{
			list_.clear();
		}

	}

	void push_back(const T &pt) 
	{
		mutex_.lock();
		list_.push_back(pt);
		mutex_.unlock();
	}

	bool pop_front(T &pt)
	{
		mutex_.lock();
		if (list_.size() > 0) 
		{
			pt = list_.front();
			list_.pop_front();
			mutex_.unlock();
			return true;
		}
		mutex_.unlock();
		return false;
	}

	void earse(T &Object) 
	{
		mutex_.lock();
		list_.remove(Object);
		mutex_.unlock();

	}

	void clear()
	{    
		mutex_.lock();
		if (!list_.empty())
		{
			list_.clear();
		}
		mutex_.unlock();
		return;
	}

	int size() 
	{
		std::string::size_type rc;
		mutex_.lock();
		rc = list_.size();
		mutex_.unlock();
		return rc;
	}

	bool empty()
	{
		mutex_.lock();
		bool rc;
		rc = list_.empty();
		mutex_.unlock();
		return rc;
	}


private:
	std::list<T> list_;
	std::mutex mutex_;
};
