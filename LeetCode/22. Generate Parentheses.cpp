// let's explain parameters of the helper function one by one.
// 1. vec is vector of strings --> result vector
// 2. i and j are iterators for opening brackets and closing brackets respectively
// 3. s is temporary string to make and add into the vec(result vector)
// 4. n is the no of pairs of paranthesis
// 5. flag is like a sign that determine whether the function called for "(" or ")".

void helper(vector<string>& vec,int i,int j,string s,int& n,bool flag) 
{
    if (flag)
    {
      if (i < n)
      {
          s += "(";
          i++;
      }
      else
          return;
    }
    else
    {
        if (j < n && j<i)
        {
            s += ")";
            j++;
            if (j == n)
            {
              vec.push_back(s);
              return;
            }
        }
        else
            return;
    }
    if(i<n)
      helper(vec, i, j, s, n, 1);
    if(j<n)
      helper(vec, i, j, s, n, 0);

}

vector<string> generateParenthesis(int n) 
{
    vector<string> vec;
    // initially vec is empty, iterators are empty, string is empty and flag is 1
    // because initially it starts from "(" for valid combination.
    helper(vec,0,0,"",n,1);
    
    return vec;      
}
