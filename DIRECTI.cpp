#include<iostream>
#include<stack>
using namespace std;

int main(){
    int T, N;
    cin >> T;


    string st;
    while(T--){
        cin >> N;
        stack<string> Road, Direction;
        int n = N;

        string loc, on,r, road;
        while(N--){
            cin >> loc >> on >> r >> road;
            Direction.push(loc);
            Road.push(road);
        }

        //get the top element from the stack Road
        cout << "Begin on Road " << Road.top() << endl;
        //pop the last element from the Road stack
        Road.pop();

        while(!Road.empty()){
            //get the top direction
            string top_dir = Direction.top();
            string curr_dir = (top_dir=="Right")? "Left": "Right";
            cout << curr_dir << " on "
        }




    }

    return 0;
}
