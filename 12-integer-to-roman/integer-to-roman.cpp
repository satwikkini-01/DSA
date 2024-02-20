class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int count = 0;
        while(num>0){
            int r = num%10;
            if(count == 0){
                switch(r){
                    case 0:
                        break;
                    case 1:
                        ans.insert(0,"I");
                        break;
                    case 2:
                        ans.insert(0,"II");
                        break;
                    case 3:
                        ans.insert(0,"III");
                        break;
                    case 4:
                        ans.insert(0,"IV");
                        break;
                    case 5:
                        ans.insert(0,"V");
                        break;
                    case 6:
                        ans.insert(0,"VI");
                        break;
                    case 7:
                        ans.insert(0,"VII");
                        break;
                    case 8:
                        ans.insert(0,"VIII");
                        break;
                    case 9:
                        ans.insert(0,"IX");
                        break;
                }
                count++;
            }
            else if(count == 1){
                switch(r){
                    case 0:
                        break;
                    case 1:
                        ans.insert(0,"X");
                        break;
                    case 2:
                        ans.insert(0,"XX");
                        break;
                    case 3:
                        ans.insert(0,"XXX");
                        break;
                    case 4:
                        ans.insert(0,"XL");
                        break;
                    case 5:
                        ans.insert(0,"L");
                        break;
                    case 6:
                        ans.insert(0,"LX");
                        break;
                    case 7:
                        ans.insert(0,"LXX");
                        break;
                    case 8:
                        ans.insert(0,"LXXX");
                        break;
                    case 9:
                        ans.insert(0,"XC");
                        break;
                }
                count++;
            }
            else if(count == 2){
                switch(r){
                    case 0:
                        break;
                    case 1:
                        ans.insert(0,"C");
                        break;
                    case 2:
                        ans.insert(0,"CC");
                        break;
                    case 3:
                        ans.insert(0,"CCC");
                        break;
                    case 4:
                        ans.insert(0,"CD");
                        break;
                    case 5:
                        ans.insert(0,"D");
                        break;
                    case 6:
                        ans.insert(0,"DC");
                        break;
                    case 7:
                        ans.insert(0,"DCC");
                        break;
                    case 8:
                        ans.insert(0,"DCCC");
                        break;
                    case 9:
                        ans.insert(0,"CM");
                        break;
                }
                count++;
            }
            else{
                switch(r){
                    case 0:
                        break;
                    case 1:
                        ans.insert(0,"M");
                        break;
                    case 2:
                        ans.insert(0,"MM");
                        break;
                    case 3:
                        ans.insert(0,"MMM");
                        break;
                }
                count++;
            }
            num /= 10;
        }
        return ans;
    }
};