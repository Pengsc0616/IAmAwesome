class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int i=1;
        while(sum<target){
            sum += (i++);
        }
        i--;
        int diff = sum - target;
        // cout << i << " " << diff << endl;
        if(diff%2 == 0) return i;
        
        return i + 1 + (i%2);
    }
};
// class Solution {
// public:
//     int reachNumber(int target) {
//         target = abs(target);
//         int position = 0;
//         int i=1;
//         while(1){
//             if((position+i==target)||(position-i==target))   return i;
//             if(position+i<target){
//                 position += i;
//                 i++;
//             }else{
//                 position -= i;
//                 i++;
//             }
//         }
//         return 0;
//     }
// };