#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab 9 - queue2        

    author: Carter Fowler

    last modified: 3/16/2018
*/

template <class T>

class Queue {
public:
    // constructor
	Queue() {
    	_queue_capacity = 0;
    	_array_size = _queue_capacity + 1;
    	_arr_ptr = new T[_array_size];
    	_front = 0;
    	_back = 0;
	}

    // enqueue: add a (whatever tyoe T is) to the end of the queue if room and return true
	void enqueue(T c) {
        if(_array_size == _queue_capacity) {
        	resize();
        	_front = 0;
        	_back = _queue_capacity - 1;
        }
        _arr_ptr[_back] = c;
        ++_array_size;
        _back = (_back + 1) % _array_size;
	}
		
    // dequeue: if queue is not empty, remove the front element from the queue;
    // if queue is empty, return false and do nothing.
	bool dequeue()  { 
		if (is_empty()) { return false; }
		_front = (_front + 1) % _array_size;
        --_queue_capacity;
		return true;
	}

    // front: return the front element in the queue
	T front() { return _arr_ptr[_front]; }

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _array_size == 0; }
	
	void resize() {
		_array_size = 2 * _array_size;
		T* new_arr_ptr = new T[_array_size];
		int j = _front;
		for(int i = 0; i < _queue_capacity; ++i) {
			new_arr_ptr[i] = _arr_ptr[j];
			++j;
			if(j == _queue_capacity) {
				j = 0;
			}
		}
		delete[] _arr_ptr;
		_arr_ptr = new_arr_ptr;
	}
	
	~Queue() {
		delete[] _arr_ptr;
	}
	
	void copy_function(const Queue<T>& temp) {
		_queue_capacity = temp._queue_capacity;
		_array_size = temp._array_size;
		_front = temp._front;
		_back = temp._back;
		_arr_ptr = new T[_array_size];
		for(int i = 0; i < _array_size; ++i) {
			_arr_ptr[i] = temp._arr_ptr[i];
		}
	}
	
	Queue(const Queue<T>& temp) {
		copy_function(temp);
	}
	
	Queue& operator=(const Queue<T>& temp) {
		if(this == &temp) {
			return *this;
		}
		delete[] _arr_ptr;
		copy_function(temp);
		return *this;
	}

private:
	T* _arr_ptr;
	int _queue_capacity;
    int _array_size;
	int _front;
	int _back;
	
};

#endif
