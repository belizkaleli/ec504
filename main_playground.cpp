//
//  main.cpp
//  vEBZack
//
//  Created by Mert TOSLALI on 12/4/18.
//  Copyright © 2018 Mert TOSLALI. All rights reserved.
//

#include <iostream>
#include "vEB.hpp"
#include "XFastTrie.hpp"
#include <vector>
#include <map>
#include "inttypes.h"
#include <time.h>
#include <math.h>

pair<int, char> foo() {
    return make_pair(1, 'c');
}

int main(int argc, const char * argv[]) {
    // insert code here...
    VEBTree *v = new VEBTree(512);

    XFastTrie xft(8);

    FILE* f = fopen("results.txt", "a+");
    time_t t;
    time_t timesVEB[(int)pow(2, 16) - 1];
    time_t timesXF[(int)pow(2, 8) - 1];
    for (int i = 0; i < pow(2, 8); i += 2) {
        Entry* e = new Entry;
        e->key = i;
        t = clock();
        xft.insert(e);
        timesXF[i] = (double)(clock() - t) / CLOCKS_PER_SEC;
        cout << i << endl;
    }

    // Entry e4 = {0};
    // xft.insert(&e4);
    // Entry e33 = {2};
    // xft.insert(&e33);
    // Entry e44 = {4};
    // xft.insert(&e44);

    cout << "Pred " << xft.getPredecessor((uint64_t) 4)->key << endl;
    cout << "Succ " << xft.getSuccessor((uint64_t) 3)->key << endl;
    cout << "Pred " << xft.getPredecessor((uint64_t) 3)->key << endl;
    cout << "Pred " << xft.getPredecessor((uint64_t) 1)->key << endl;

    cout << "Is 4 here: " << xft.lookup(4) << endl;
    cout << "Is 3 here: " << xft.lookup(3) << endl;

    // cout << "Now goes VEB" << endl;

    // for (int i = 0; i < pow(2, 16); i++) {
    //     t = clock();
    //     v->insert(i);
    //     timesVEB[i] = (double)(clock() - t) / CLOCKS_PER_SEC;
    // }
    // fclose(f);

    // Entry e4 = {8};
    // xft.insert(&e4);
    // Entry e33 = {12};
    // xft.insert(&e33);
    // Entry e44 = {13};
    // Entry e = {5};
    // xft.insert(&e);
    // Entry e1 = {6};
    // xft.insert(&e1);
    // Entry e2 = {6};
    // xft.insert(&e2);
    // Entry e3 = {4};
    // xft.insert(&e3);
    // xft.insert(&e44);
    // Entry e331 = {9};
    // xft.insert(&e331);
    // Entry e441 = {34};
    // xft.insert(&e441);

    // xft.del((uint64_t) 6);

    // Entry e0 = {2};
    // xft.insert(&e0);
    // Entry e333 = {7};
    // xft.insert(&e333);
    // Entry e444 = {11};
    // xft.insert(&e444);
    // Entry e55 = {13};
    // xft.insert(&e55);
    // Entry e11 = {3};
    // xft.insert(&e11);
    // Entry e22 = {5};
    // xft.insert(&e22);

    // cout << "Predecessor 9: " << xft.getPredecessor((uint64_t) 9)->key << endl;
    // cout << xft.getSuccessor((uint64_t) 4)->key << endl;

    // Entry entries[240];
    // for (int i = 0; i < 240; i++) {
    //     // cout << "insert " << i << endl;
    //     entries[i].key = i;
    //     xft.insert(&entries[i]);
    // }

    // cout << "Getlen: " << xft.getLen() << endl;

    // cout << xft.getMax()->key << endl;
    // printf("Max: %lu\n", xft.getMax()->key);
    // printf("Min: %lu\n", xft.getMin()->key);
    // printf("Len: %d\n", xft.getLen());
    // Entry* suc_5 = xft.getSuccessor((uint64_t)5);
    // Entry* suc_7 = xft.getSuccessor((uint64_t)7);
    // Entry* pred_7 = xft.getPredecessor((uint64_t)7);
    // Entry* pred_6 = xft.getPredecessor((uint64_t)6);
    // printf("Suc5: %lu\n", suc_5->key);
    // printf("Pred6: %lu\n", pred_6->key);
    // printf("Succ7: %lu Pred7: %lu\n", suc_7->key, pred_7->key);

    // cout << "Should delete " << endl;
    // xft.del((uint64_t) 5);
    // xft.del((uint64_t) 9);
    // xft.del((uint64_t) 12);
    // xft.del((uint64_t) 13);

    // for (int i = 0; i < 240; i++) {
    //     cout << "delete " << i << endl;
    //     xft.del((uint64_t) i);
    // }


    // // printf("%d\n", v -> getMax());
    // // printf("%d\n", v -> getMin());
    // // printf("%d\n", (v -> successor(9)));
    // // printf("%d\n", (v -> predecessor(9)));
    // // printf(v->findItem(9)?"found\n":"not found\n");

    return 0;
}
