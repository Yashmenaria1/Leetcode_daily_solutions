class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
	    int count = students.size(), circular_stu=0, square_stu=0;
	    for(int i = 0; i < students.size(); i++){
		    if(students[i] == 0)  
                circular_stu++;
		    else{
                square_stu++;
            }
	    }
	    for(int i = 0; i < sandwiches.size(); i++){
		    if(sandwiches[i] == 0){
			    if(circular_stu > 0){
				    count--;
				    circular_stu--;
                }  
			    else{
                    return count;
                }
		    }
		    else{
			    if(square_stu > 0){
				    count--;
				    square_stu--;
                }
			    else{
                    return count;
                }
		    }
	    }
	    return count;
    }
};
