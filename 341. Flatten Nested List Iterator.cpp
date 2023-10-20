class NestedIterator {
public:
    vector<int>list;
    int index;
    NestedIterator(vector<NestedInteger> &nestedList) {
        listIterator(nestedList);
        index = 0;
    }

    void listIterator(vector<NestedInteger> &nestedList){
        for(int i = 0; i<nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                list.push_back(nestedList[i].getInteger());
            }
            else{
                listIterator(nestedList[i].getList());
            }
        }
    }
    
    int next() {
        return list[index++];
    }
    
    bool hasNext() {
        return index<list.size();
    }
};
