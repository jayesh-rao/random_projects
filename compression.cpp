/*
 * Problem:
 * abc ==> a1b1c1
 * aaaabbccccccc => a4b2c7
 * */


#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// abc --> abc\0FFF
int displacement(int idx) { return 2*idx; }
int replace(int val) { return 2*(val-1); }

void compress_the_damm_string(char* ip) {
    cout <<  ip << " " << string(ip).size();
    size_t sz = strlen(ip);
    int to_move = sz/2-1;

    // displacing the original characters
    while(to_move !=0) {
        ip[displacement(to_move)] = ip[to_move];
        to_move--;
    }

    cout << "\n" << ip << "\n";
    
    int to_process = 0, count = 1;
    int distinct_char = 0;
    int idx = to_process;

    // count the repeated occurrences of characters, and put the count in appropriate position.

    while (idx < sz) {
        
        idx += 2;
        while (ip[idx] == ip[to_process]) { 
            count++;
            idx += 2; 
            
        }
        distinct_char++;
    
        // idx will point to a char which wont match the ip[to_prcess]
        //char ch = count;
        ip[to_process + 1] = static_cast<char>(count);
        to_process = idx;
        count = 1;
    }
    
    int num = distinct_char;

    // process the counts and replace appropriately.
    {

        //pick the element count
        to_process = 0; // note that to_prcess + 1 will give me the count
        int to_replace = 0;
        while (to_process < sz || distinct_char != 0 ) {
            to_replace = to_replace + 2;
            count = static_cast<int>(ip[to_process + 1]);
            //if (count < 2) { to_process += 2; continue; }
            int tgt_idx = to_process + 2 + replace(count);

            ip[to_replace] = ip[tgt_idx];
            ip[to_replace + 1] = ip[tgt_idx + 1];
            to_process = tgt_idx;
            --distinct_char;
        }

    }

    // finally print the stuff
    cout << "\n compressed:  ";
    for (int i = 0; i < 2*num; i++) {
        if (i%2) cout << "  " << static_cast<int>(ip[i]);
        else cout << " " << ip[i];
    }
    //cout << "\n" << ip << "  " << strlen(ip) << "   " << distinct_char;
}

int main()
{
    
    string str = "a";
    size_t sz = str.size();
    char *s = (char*)malloc(2*sz+1);
    memset(s+sz, '-', sz);
    s[2*sz] = '\0';
    
    
    memcpy(s, str.c_str(), sz);
    
    compress_the_damm_string(s);

    cout << "\n";

    return 0;
}



