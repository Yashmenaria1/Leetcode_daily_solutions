class MyStack{
public:
    queue <int> q;
    MyStack() {

    }
    void push(int x){
        int n = q.size();
        q.push(x);
        while(n--){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int result = top();
        q.pop();
        return result;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};
