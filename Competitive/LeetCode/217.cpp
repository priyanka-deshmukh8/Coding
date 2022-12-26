 int firstUniqChar(string s) {
        for (int i=0;i<s.length();i++){
        bool unique = true;
        
        for(int j=0;j<s.length();j++)
        {
            if(i!=j && s.charAt(i)==s.charAt(j)){
                unique = false;
                break;
            }
        }
        if(unique){
            return i;
        }
    }
    return -1;
}
