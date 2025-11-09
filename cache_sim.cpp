#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct CacheEntry {
    bool valid;
    long long tag; 
};

// Function to run the simulation logic
void run_simulation(int num_entries, int associativity, const string& input_file_name, const string& output_file_name) {
    
    // Calculate the number of sets (S)
    if (associativity == 0) {
        cerr << "Error: Associativity cannot be zero." << endl;
        return;
    }
    const int num_sets = num_entries / associativity; 
    const int ways = associativity; 

    // Initialize the cache structure
    vector<vector<CacheEntry>> cache(num_sets, vector<CacheEntry>(ways));
    
    // Tracks which way in the set should be replaced next upon a capacity miss.
    vector<int> replacement_index(num_sets, 0); 

    // Open input and output files
    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);

    if (!input_file.is_open()) {
        cerr << "Error: Could not open input file: " << input_file_name << endl;
        return;
    }
    if (!output_file.is_open()) {
        cerr << "Error: Could not open output file: " << output_file_name << endl;
        return;
    }

    // Read all memory references from the input file 
    string line;
    if (getline(input_file, line)) {
        stringstream ss(line);
        long long address;

        // Process each memory reference
        while (ss >> address) {
            
       
            
            // Set Index (I) = Address % Number of Sets
            int set_index = address % num_sets;
            
            // Tag (T) = Address / Number of Sets (integer division)
            long long tag = address / num_sets;

            bool is_hit = false;
            int available_way = -1; // Used to track an invalid entry for placement

            // 1. Check for a Hit
            for (int w = 0; w < ways; ++w) {
                CacheEntry& entry = cache[set_index][w];
                
                if (entry.valid && entry.tag == tag) {
                    is_hit = true;
                    break; 
                }
                
                if (!entry.valid && available_way == -1) {
                    // Record the first available (invalid) slot
                    available_way = w;
                }
            }

            string result;
            
            if (is_hit) {
                // HIT detected
                result = "HIT";
            } else {
                // MISS detected
                result = "MISS";

                // 2. Handle Miss: Placement/Replacement
                int placement_way;

                if (available_way != -1) {
                    // Case 1: Compulsory Miss (Empty slot available)
                    placement_way = available_way;
                } else {
                    // Case 2: Conflict/Capacity Miss (Set is full, use replacement policy)
                  
                    placement_way = replacement_index[set_index];
                    
                    // Update the replacement pointer for the next eviction
                    replacement_index[set_index] = (replacement_index[set_index] + 1) % ways;
                }
                
                // Load the new entry into the determined way
                cache[set_index][placement_way].valid = true;
                cache[set_index][placement_way].tag = tag;
            }

            // Write output in the required format: [ADDR] : [HIT or MISS] 
            output_file << address << " : " << result << endl;
        }
    }
    
    // Close files
    input_file.close();
    output_file.close();
}

// Main execution block
int main(int argc, char* argv[]) {
    
    // Check for correct number of command-line arguments 
    if (argc != 5) {
        cerr << "Usage: " << argv << " num_entries associativity input_memory_reference_file" << endl;
        return 1;
    }

    // Parse command line arguments
    int num_entries = stoi(argv[2]);
    int associativity = stoi(argv[3]);
    string input_file_name = argv[4];

    
    // Define the required output file name 
    const string output_file_name = "cache_sim_output"; 

    // Run the core simulation
    run_simulation(num_entries, associativity, input_file_name, output_file_name);

    // cout << "Simulation complete. Results written to: " << output_file_name << endl;

    return 0;
}