class MyHashMap {
public:
    int data[1000001];
    MyHashMap() {
        fill(data, data + 1000000, -1);
    }
    void put(int key, int val) {
        data[key] = val;
    }
    int get(int key) {
        return data[key];
    }
    void remove(int key) {
        data[key] = -1;
    }
};

//JAVA solution
// class MyHashMap {
//     int [] data;
//     public MyHashMap() {
//         data = new int[1000001];
//         Arrays.fill(data, -1);
//     }
    
//     public void put(int key, int value) {
//         data[key] = value;
//     }
    
//     public int get(int key) {
//         return data[key];
//     }
    
//     public void remove(int key) {
//         data[key] = -1;
//     }
// }
