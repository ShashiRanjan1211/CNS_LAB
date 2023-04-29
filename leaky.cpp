#include <iostream>
#include <chrono>
#include <unistd.h> 
#include <ctime> 
using namespace std;
int main() {
    int bucket_size, output_rate, new_traffic_rate;
    cout << "Enter the size of the bucket (in units): ";
    cin >> bucket_size;
    cout << "Enter the output rate (in units per second): ";
    cin >> output_rate;
    cout << "Enter the rate of new traffic (in units per second): ";
    cin >> new_traffic_rate;
    int bucket_level = 0; 
    auto last_output_time = chrono::system_clock::now();   
    while (true) {
        auto current_time = chrono::system_clock::now();
        auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(current_time - last_output_time);
        int elapsed_seconds = elapsed_time.count() / 1000;   
        if (bucket_level > 0 && elapsed_seconds > 0) {
            int output_units = min(bucket_level, output_rate * elapsed_seconds);
            bucket_level -= output_units;
            time_t timestamp = chrono::system_clock::to_time_t(current_time);
            cout << "Output " << output_units << " units at " << ctime(&timestamp) << endl;
            last_output_time = current_time;
        }
        int new_traffic = min(new_traffic_rate * elapsed_seconds, bucket_size - bucket_level);
        bucket_level = min(bucket_level + new_traffic, bucket_size);
        sleep(1); 
    }
    return 0;
}
