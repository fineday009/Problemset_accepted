#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    int T, n;
    while(cin>>T){
        while(T--){
            cin>>n;//总数有n个,且输出是1 2 3 4 5...n

            //reverse op
            int times=n;
            deque<int> deq(1, times--);
            while(times>0){
                deq.push_front(deq.back());
                deq.pop_back();

                if(times>0) deq.push_front(times--);
            }
            deq.push_front(deq.back());
            deq.pop_back();

            int size=deq.size();
            for(int i=0; i<size; ++i) printf("%d%c", deq[i], i==size-1?'\n':' ');
        }
    }

    return 0;
}


//#include <deque>
//#include <iostream>
//#include <algorithm>
//#include <iterator>
//
//using namespace std;
//
//int main() {
//	deque<int> intDqe;
//	ostream_iterator<int> screen(cout, " ");
//
//	// 从双端队列的尾部添加元素
//	intDqe.push_back(13);
//	intDqe.push_back(75);
//	intDqe.push_back(28);
//	intDqe.push_back(35);
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// 从双端队列的首部添加元素
//	intDqe.push_front(0);
//	intDqe.push_back(100);
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// 从首部删除两个元素
//	intDqe.pop_front();
//	intDqe.pop_front();
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// 从尾部删除两个元素
//	intDqe.pop_back();
//	intDqe.pop_back();
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// 构造双端队列的迭代器
//	deque<int>::iterator deqIt;
//	deqIt = intDqe.begin();
//	++deqIt;
//
//	// 插入元素
//	intDqe.insert(deqIt,444);
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// 重新赋值，两个相同元素
//	intDqe.assign(2,45);
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// 从首部和尾部添加元素
//	intDqe.push_front(-10);
//	intDqe.push_back(-1999);
//
//	// 输出到控制台
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//	return 0;
//}


用vector:
//作者：xxx
//将顺序序列处理得出结果
//比如1 2 3 4 5，先将5插入到3、4之间（隔1），得到1 2 3 5 4，再将4插入到2、3之间（隔2），得到1 2 4 3 5，再将5插入
//到1、2之间（隔3），得到1 5 2 4 3，最后将3插入到1前面（隔4），得到最终结果：3 1 5 2 4
//从上面例子可看出，不断的将最后一个元素插入到前面，规律为相隔元素个数依次递增，上面是从1到4
#include<iostream>
#include<vector>
using namespace std;
 
int main() {
    int t;
    while (cin >> t) {
        while (t) {
            int n;
            cin >> n;
            vector<int> vec;
            for (int i = 1; i <= n; i++) {
                vec.push_back(i);
            }
            for (int i = 1; i < n; i++) {
                int tmp = *(vec.end() - 1);
                vec.insert(vec.end() - i - 1, tmp);
                vec.pop_back();
            }
            bool flag = true;
            for (int i : vec) {
                if (flag) {
                    flag = false;
                    cout << i;
                }
                else
                    cout << " " << i;
            }
            cout << endl;
            t--;
        }
    }
}