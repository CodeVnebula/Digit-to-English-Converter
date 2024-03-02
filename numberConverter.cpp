#include <iostream>
#include <string>
using namespace std;

string basicNumbers(int number)
{
    // This function is for providing basic numbers when needed
    switch(number)
    {
        case 0: return "Zero"; break;
        case 1: return "One"; break;
        case 2: return "Two"; break;
        case 3: return "Three"; break;
        case 4: return "Four"; break;
        case 5: return "Five"; break;
        case 6: return "Six"; break;
        case 7: return "Seven"; break;
        case 8: return "Eight"; break;
        case 9: return "Nine"; break;
        case 10: return "Ten"; break;
    }
    return 0;
}

int digitsCounter(int number)

{
    if(number == 0)
        return 1;       
    
    int count = 0;
    while(number != 0)
    {
        number /= 10;
        count++;        //if number doesn't equal 0 then updating counter by one
    }
    return count;
}

string tenToHundred(int number)
{
    switch (number)
    {
    case 20: return "Twenty"; break;      // numbers like 20, 30, 40, 50 have different types than other nums like 60, 70...
    case 30: return "Thirty"; break;      // others can be shown as - basicnum + "ty"
    case 40: return "Forty"; break;
    case 50: return "Fifty"; break;
    }
    return 0;
}

string tenTofifteen(int number)
{
    switch (number)
    {
    case 11: return "Eleven"; break;
    case 12: return "Twelve"; break;
    case 13: return "Thirteen"; break;
    case 15: return "Fifteen"; break;
    }
    return 0;
}


int main()
{
    long long int number;
    cout << "Enter number: "; cin >> number;
    int length = digitsCounter(number);     // calculating length of input

    


    if(length == 1)
    {
        cout << basicNumbers(number);   // if there is only one digit in num so its < 10 and > 0
                                        // so it can be displayed as basic nums
    }
    
    else if(length == 2)
    {
        if(number % 10 == 0)            // when the number is between 10 and 100 so it has 2 digits
        {                               // first checking if number divided by 10 is 0
            if(number <= 50 && number >= 20)
                cout << tenToHundred(number);   
            
            else if(number == 10)
                cout << basicNumbers(number);

            else
                if(number / 10 == 8)
                    cout << basicNumbers(number / 10) << "y";   // 80 needs one t
                else
                    cout << basicNumbers(number / 10) << "ty";
        }                 
        else if(number < 20 && number % 10 != 0)
        {
            if(number <= 15 && number != 14)
                cout << tenTofifteen(number);
            else if(number == 18)
                cout << basicNumbers(number % 10) << "een";
            else
                cout << basicNumbers(number % 10) << "teen";
        }   
        else 
        {
            if(number > 20 && number < 60)
                cout << tenToHundred(number - (number % 10)) << " " << basicNumbers(number % 10);
            else if(number > 80 && number < 90)
                cout << basicNumbers(number / 10) << "y " << basicNumbers(number % 10);
            else 
                cout << basicNumbers(number / 10) << "ty " << basicNumbers(number % 10);
        }
    }

    else if(length == 3)
    {
        if(number % 100 == 0)       // if number is exactly divisible by 100
            cout << basicNumbers(number / 100) << " Hundred";
        else if(number % 10 == 0 && number % 100 != 0)      // if number is exactly divisible by 10 but not 100
        {
            if(number % 100 == 10)      // checking if num is more than x times hundred by 10
                cout << basicNumbers(number / 100) << " Hundred " << basicNumbers(number % 100);
            else if(number % 100 <= 50)
                cout << basicNumbers(number / 100) << " Hundred " << tenToHundred(number % 100);
            else if(number % 100 == 80)
                cout << basicNumbers(number / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "y";
            else
                cout << basicNumbers(number / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "ty";
        }
        else    // if number is not exactly divisible by 10 or 100
        {
            if(number % 100 < 10 && number % 100 != 0)
                cout << basicNumbers(number / 100) << " Hundred " << basicNumbers(number % 100);
                
            else if(number % 100 > 10 && number % 100 <= 15)    
            {
                if(number % 100 != 14)
                    cout << basicNumbers(number / 100) << " Hundred " << tenTofifteen(number % 100);
                else
                    cout << basicNumbers(number / 100) << " Hundred " << basicNumbers(number % 10) << "teen";
            }
            else if(number % 100 > 15 && number % 100 < 20)
            {
                if(number % 100 == 18)
                    cout << basicNumbers(number / 100) << " Hundred " << basicNumbers(number % 10) << "een";
                else
                    cout << basicNumbers(number / 100) << " Hundred " << basicNumbers(number % 10) << "teen";
            }
            else
            {
                if(number % 100 > 20 && number % 100 < 60)
                    cout << basicNumbers(number / 100) << " Hundred " << tenToHundred((number % 100) - (number % 10)) << " " << basicNumbers(number % 10);
                else if(number % 100 > 80 && number % 100 < 90)
                    cout << basicNumbers(number / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "y " << basicNumbers(number % 10);
                else
                    cout << basicNumbers(number / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "ty " << basicNumbers(number % 10);
            }
        }
    }
   




   else if(length == 4)
   {
        if(number % 1000 == 0)
        {
            cout << basicNumbers(number / 1000) << " Thousand";
        }
        else if(number % 1000 < 1000)
        {
            if(number % 1000 >= 100)
            {       
                // for nums over 1100, 2100, 3100, 4100, 5100, 6100, 7100, 8100, 9100!
                if(number % 100 == 0)       // for nums correctly divisible by 100
                    cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
                
                else
                {
                    if(number % 10 == 0)        // for nums divisible by 10
                    {


                        if(number % 100 == 10)      
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);

                        else if(number % 100 <= 50)
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << tenToHundred(number % 100);
                        
                        else if(number % 100 == 80)
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "y";
                        
                        else
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "ty";
                    }

                    else if(number % 100 < 10)
                        cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) % 10);
                    
                    else if(number % 100 < 20)
                    {
                        if(number % 100 <= 15)
                        {
                            if(number % 100 != 14)
                                cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << tenTofifteen(number % 100);
                            else if(number % 100 == 14)
                                cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) % 10) << "teen";
                            
                        }
                        else
                        {
                            if(number % 100 == 18)
                                cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) % 10) << "een";
                            else if(number % 100 != 18)
                                cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) % 10) << "teen";
                        }

        
                        
                    }

                    else if(number % 100 < 60)
                        cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << tenToHundred((number % 100) - (number % 10)) << " " << basicNumbers(number % 10);

                    else
                    {
                        if(number % 100 > 80 && number % 100 < 90)
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "y " << basicNumbers(number % 10);
                    
                        else 
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers((number % 100) / 10) << "ty " << basicNumbers(number % 10);
                    }
    
                }
            }
            
            
            else if(number % 1000 < 100)
            {
                if(number % 10 == 0)        // for nums divisible by 10
                {


                        if(number % 100 == 10)      
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers(number % 100);

                        else if(number % 100 <= 50)
                            cout << basicNumbers(number / 1000) << " Thousand " << tenToHundred(number % 100);
                        
                        else if(number % 100 == 80)
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) / 10) << "y";
                        
                        else
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) / 10) << "ty";
                }

                else if(number % 100 < 10)
                        cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) % 10);


                else if(number % 100 < 20)
                {
                    if(number % 100 <= 15)
                    {
                        if(number % 100 != 14)
                            cout << basicNumbers(number / 1000) << " Thousand " << tenTofifteen(number % 100);
                        else if(number % 100 == 14)
                            cout << basicNumbers(number / 1000) << " Thousand " << " Hundred " << basicNumbers((number % 100) % 10) << "teen";
                            
                    }
                    else
                    {
                        if(number % 100 == 18)
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) % 10) << "een";
                        else if(number % 100 != 18)
                            cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) % 10) << "teen";
                    }
                }

                else if(number % 100 < 60)
                    cout << basicNumbers(number / 1000) << " Thousand " << tenToHundred((number % 100) - (number % 10)) << " " << basicNumbers(number % 10);

                else
                {
                    if(number % 100 > 80 && number % 100 < 90)
                        cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) / 10) << "y " << basicNumbers(number % 10);
                    
                    else 
                        cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 100) / 10) << "ty " << basicNumbers(number % 10);
                }


            }
        }
    }

/*
    else if(length == 4 || length == 5)
    {


        if(number % 10000 == 0)         // for 10000 20000 30000....90000
        {
            if(number / 10000 == 1)
                cout << basicNumbers(number / 1000) << " Thousand";
            else if(number / 10000 >= 2 && number / 10000 <= 5)
                cout << tenToHundred(number / 1000) << " Thousand";
            else if(number / 10000 == 8) 
                cout << basicNumbers(number / 10000) << "y" << " Thousand";
            else
                cout << basicNumbers(number / 10000) << "ty" << " Thousand";
        }



        else if(number % 1000 == 0 && number % 10000 != 0)      // for 2, 3,  10, 15, 54, 99000...
        {
            if(number / 1000 < 10)
                cout << basicNumbers(number / 1000) << " Thousand";     // for 1000 - 10000 thousands
            else if(number / 1000 <= 15)
            {
                if(number / 1000 != 14)
                    cout << tenTofifteen(number / 1000) << " Thousand";
                else                                                                // for 10000 - 15000 thousands
                    cout << basicNumbers((number % 10000) / 1000) << "teen" << " Thousand";
            }
            else if(number / 1000 < 20)
            {
                if(number / 1000 != 18)
                    cout << basicNumbers((number % 10000) / 1000) << "teen" << " Thousand";     // for 15000 - 20000 thousands
                else
                    cout << basicNumbers((number % 10000) / 1000) << "een" << " Thousand";
            }
            else if(number / 1000 > 20 && number / 1000 < 60)           // for 20 - 60000 thousands
                cout << tenToHundred((number / 1000) - ((number % 10000) / 1000)) << " " << basicNumbers((number % 10000) / 1000) << " Thousand";
            else if(number / 1000 > 80 && number / 1000 < 90)
                cout << basicNumbers((number / 10000)) << "y " << basicNumbers((number / 1000) % 10) << " Thousand";
            else
                cout << basicNumbers((number / 10000)) << "ty " << basicNumbers((number / 1000) % 10) << " Thousand";
        }  

   
   
        


        else if(number % 100 == 0 && number % 1000 != 0)
        {
            if(number / 100 <= 100)
                cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
            else if(number / 100 < 160)
            {
                if(number / 100 < 140 || number / 100 >= 150)
                    cout << tenTofifteen(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
                else
                   cout << basicNumbers((number % 10000) / 1000) << "teen" << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
            }   
            else if(number / 100 < 200)
            {
                if(number / 100 > 180 && number / 100 < 190)
                    cout << basicNumbers((number % 10000) / 1000) << "een" << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
                else
                    cout << basicNumbers((number % 10000) / 1000) << "teen" << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
            }
            else if(number / 100 < 600)
                cout << tenToHundred((number / 1000) - ((number % 10000) / 1000)) << " " << basicNumbers((number % 10000) / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
            else if(number / 100 > 800 && number / 100 < 900)
                cout << basicNumbers(number / 10000) << "y " << basicNumbers((number % 10000) / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
            else
                cout << basicNumbers(number / 10000) << "ty " << basicNumbers((number % 10000) / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred";
        }



        else if(number % 10 == 0 && number % 100 != 0 && number % 1000 != 0 && number % 10000 != 0)
        {
            if(number % 10 == 0)
            {
                if(number % 1000 <= 10)
                    cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers(number % 1000);
                else if(number % 1000 >= 20 && number % 1000 < 60)
                    cout << basicNumbers(number / 1000) << " Thousand " << tenToHundred(number % 1000);
                else if(number % 1000 != 80)
                    cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 10) << "ty";
                else  
                    cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 10) << "y";
            }
            else if(number % 100 == 10)
            {
                if(number / 1000 < 10)
                    cout << basicNumbers(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
                else if(number / 1000 <= 15)
                {
                    if(number / 1000 != 14)
                        cout << tenTofifteen(number / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
                    else
                        cout << basicNumbers((number % 10000) / 1000) << "teen" << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
                }
                else if(number / 1000 < 20)
                {
                    if(number / 1000 == 18)
                        cout << basicNumbers((number % 10000) / 1000) << "een" << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
                    else 
                        cout << basicNumbers((number % 10000) / 1000) << "teen" << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
                }
                else if(number / 1000 > 20 && number / 1000 < 60)
                    cout << tenToHundred((number / 1000) - ((number % 10000) / 1000)) << " " << basicNumbers(((number % 10000) / 1000)) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
                else if(number / 1000 > 80 && number % 1000 < 90)
                    cout << basicNumbers((number / 1000) / 10) << "y " << basicNumbers((number % 10000) / 1000) << " Thousand " << basicNumbers((number % 1000) / 100) << " Hundred " << basicNumbers(number % 100);
            }

            

            
        }
    }   
*/





    

    return 0;
}