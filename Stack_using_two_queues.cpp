void QueueStack :: push(int x)
{
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
         q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        int x;
        if(q1.empty() && q2.empty()) return -1;
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        int len = q1.size();
        while(len > 1) {
            q2.push(q1.front());
            q1.pop();
            len--;
        }
        x = q1.front();
        q1.pop();
        return x;
}
