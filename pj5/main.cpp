#include "main.h"

int main()
{
    try
    {
        Vector<int> v1;

        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(6);
        v1.push_back(7);
        v1.push_back(8);
        v1.push_back(9);
        v1.push_back(10);

        cout << "size is " << v1.size() << endl;
        cout << "cap is " << v1.capacity() << endl;

        v1.insert(3, 999);

        cout << "size is " << v1.size() << endl;
        cout << "cap is " << v1.capacity() << endl;

        v1.sort();

        cout << v1[0] << endl;
        cout << v1[1] << endl;
        cout << v1[2] << endl;
        cout << v1[3] << endl;
        cout << v1[4] << endl;
        cout << v1[5] << endl;
        cout << v1[6] << endl;
        cout << v1[7] << endl;
        cout << v1[8] << endl;
        cout << v1[9] << endl;
        cout << v1[10] << endl;

        Vector<int> v10;

        v10 = v1;

        cout << v10[0] << endl;
        cout << v10[1] << endl;
        cout << v10[2] << endl;
        cout << v10[3] << endl;
        cout << v10[4] << endl;
        cout << v10[5] << endl;
        cout << v10[6] << endl;
        cout << v10[7] << endl;
        cout << v10[8] << endl;
        cout << v10[9] << endl;
        cout << v10[10] << endl;        

        

        // cout << v1[0] << endl;

        // v1.resize(2);
        // cout << "after resize" << endl;
        // cout << v1[0] << endl;
        // cout << v1[1] << endl;


        // v1.remove(0);
        // cout << v1[0] << endl;




        // Vector<string> v2(20, "WHAT");

        // v2.push_back("a");
        // v2.push_back("b");
        // v2.push_back("c");
        // v2.push_back("d");
        // v2.push_back("e");
        // v2.push_back("f");
        // v2.push_back("g");
        // v2.push_back("h");
        // v2.push_back("i");
        // v2.push_back("j");

        // cout << v2[19] << endl; 

        // Vector<string> v3;

        // v3 = v2;

        // cout << v3[0] << endl;

    } catch (bad_alloc &e) {
        cout << "bad_alloc caught in main" << endl;
        cout << e.what() << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl; 
    } catch ( ... ) {
        cout << "unknown exception caught in main" << endl;
    }


    cout << "Successful termination!\n";

    return 0;
}