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
            cin>>n;//������n��,�������1 2 3 4 5...n

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
//	// ��˫�˶��е�β�����Ԫ��
//	intDqe.push_back(13);
//	intDqe.push_back(75);
//	intDqe.push_back(28);
//	intDqe.push_back(35);
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// ��˫�˶��е��ײ����Ԫ��
//	intDqe.push_front(0);
//	intDqe.push_back(100);
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// ���ײ�ɾ������Ԫ��
//	intDqe.pop_front();
//	intDqe.pop_front();
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// ��β��ɾ������Ԫ��
//	intDqe.pop_back();
//	intDqe.pop_back();
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// ����˫�˶��еĵ�����
//	deque<int>::iterator deqIt;
//	deqIt = intDqe.begin();
//	++deqIt;
//
//	// ����Ԫ��
//	intDqe.insert(deqIt,444);
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// ���¸�ֵ��������ͬԪ��
//	intDqe.assign(2,45);
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//
//	// ���ײ���β�����Ԫ��
//	intDqe.push_front(-10);
//	intDqe.push_back(-1999);
//
//	// ���������̨
//	copy(intDqe.begin(),intDqe.end(),screen);
//	cout << endl;
//	return 0;
//}


��vector:
//���ߣ�xxx
//��˳�����д���ó����
//����1 2 3 4 5���Ƚ�5���뵽3��4֮�䣨��1�����õ�1 2 3 5 4���ٽ�4���뵽2��3֮�䣨��2�����õ�1 2 4 3 5���ٽ�5����
//��1��2֮�䣨��3�����õ�1 5 2 4 3�����3���뵽1ǰ�棨��4�����õ����ս����3 1 5 2 4
//���������ӿɿ��������ϵĽ����һ��Ԫ�ز��뵽ǰ�棬����Ϊ���Ԫ�ظ������ε����������Ǵ�1��4
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