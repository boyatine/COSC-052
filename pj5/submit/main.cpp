#include "main.h"


int main(int argc, const char * argv[])
{
    try
    {

        Vector <int> test1;

        test1.push_back(12);
        test1.push_back(20);
        test1.push_back(96);
        test1.push_back(45);
        test1.push_back(17);

       // test1.remove(3);

        test1.assign(3, 90);

      // Vector <int> test2(test1);

       //for (int i=0; i < test2.size(); i++)
       //{
         //  cout << "test2"<< endl;
           //cout<< test2.at(i) << endl;
       //}

       //cout<< test2.capacity() << " test 2 capacity"<< endl;



        //test1.insert(0, 1000);

        //test1.sort();
        //Vector(test1);

        //test1.remove(3);

        //Vector <int> test2;

        //cout << test2.size() << endl << test2.capacity()<< endl;

        //test2=test1;

        //cout << test2.size() << endl << test2.capacity()<< endl;


        //test1.resize(20, 89);

        for (unsigned i=0; i< test1.size(); i++)
        {
            cout << "test1" << endl;
            cout << test1.at(i)<< endl;
        }

        //cout<< test1[3] << endl;


    }

    catch (std::out_of_range &or0)
    {
        cout << "caught out_of_range in function main()\n";
        cout << or0.what() << endl;
    }
    catch(std::bad_alloc &ba0)
    {
        cout << "caught bad_alloc in function main()\n";
        cout << ba0.what() << endl;
    }
    catch (...)
    {
        cout << "unknown exception caught in function main." << endl;
    }

    return 0;

} // END function main
