#include <iostream>
#include <chrono>
#include <thread>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
    int bucket_size, output_rate, input_size;
    int bucket_content = 0;
    cout << "Enter the bucket size: ";
    cin >> bucket_size;
    cout << "Enter the output rate: ";
    cin >> output_rate;
    srand(time(NULL));
    while (true) {
        input_size=rand()%10+1;
        cout<<"input size: "<<input_size<<endl;
        bucket_content += input_size;
        if (bucket_content > bucket_size) {
            cout << "Bucket overflowed!" << endl;
            bucket_content = bucket_size;
        }
        int output_amount = min(bucket_content, output_rate);
        bucket_content -= output_amount;

        this_thread::sleep_for(chrono::seconds(1));
        cout << "Outputting " << output_amount << " units of water." << endl;
        cout << "Current bucket content: " << bucket_content << endl;
    }
    return 0;
}
