#include <iostream>
#include <string>

using namespace std;

bool getValidString(const string &cardInput, string &cardNo)
{
    for (int i = 0; i < cardInput.size(); i++)
    {
        if (cardInput[i] != ' ')
        {
            if (cardInput[i] < '0' || cardInput[i] > '9')
                return false;
            cardNo.push_back(cardInput[i]);
        }
    }
    return true;
}
bool checker(const string &cardInput, string &errmess)
{
    int sum = 0;
    string cardNo;
    if (!getValidString(cardInput, cardNo))
    {
        errmess = "Fails - Card number should only have digits \n";
        return false;
    }
    if (cardNo.size() < 12 || cardNo.size() > 19)
    {
        errmess = "Fails - Card number should have 12 to 19 Digits \n";
        return false;
    }
    for(int i=cardNo.size()-1;i>=0;i-=2){
        sum+=cardNo[i]-'0';
    }
    for(int i=cardNo.size()-2;i>=0;i-=2){
        int num = cardNo[i]-'0';
        num*=2;
        if(num > 9){
            num = num%10 + num/10;
        }
        sum+=num;
    }
    if (sum == 0)
    {
        errmess = "Fails - Card number could not be zero \n";
        return false;
    }
    if (sum % 10 == 0) return true;
    
    errmess = "Fails - Card number fails luhns algorithm \n";
    return false;
}
int main()
{
    cout << "Enter card number : ";
    string cardInput;
    string errmess;
    getline(cin, cardInput);
    bool flag = checker(cardInput,errmess);
    if(flag){
        cout<<"The card number is correct \n";
    }else{
        cout<<errmess;
    }
}
