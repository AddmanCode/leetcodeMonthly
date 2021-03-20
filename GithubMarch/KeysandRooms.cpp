class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;// taking set to save the visited rooms
        visited.insert(0);//starting from room number 0
        
        stack<int> st;//taking stack (DFS approach!)
        st.push(0);//pushing the first node or room in the stack!
        
        while(!st.empty()) {//traversing untill the stack is not empty!
            vector<int> keys = rooms[st.top()];//taking vector keys as every room have some keys to access other rooms, saving those keys in vector keys
            st.pop();//popping the node from stack as it's keys has been fetched! 
            for(int key : keys ) {//traversing through the keys vector, checking all the keys
                std::set<int>::iterator it;// taking iterator
                it=visited.find(key);
                if(it == visited.end()) {//checking if it was in visited or not, means if room is already visited or not
                    visited.insert(key);//if not visited then adding it to visited vector
                    st.push(key);//also pushing it to stack as well
                }
            }
        }
        return visited.size() == rooms.size(); //returnig true if size is same, means all the rooms are visited else this will return false!
    }
};