//
// Created by noiem on 5/31/2023.
//
#include "knn.h"
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>

KnnClassifier::KnnClassifier(int k_, bool normalize_):k(k_), normalize(normalize_){}

bool ascending(pair<double, int> & lhs, pair<double, int> & rhs) {
    return lhs.first < rhs.first;
}

void norm(vector<vector<double>> & trainset) {
    //normalizing the dataset so that we have a "kind of approximate" scale
    int rowsize = trainset[0].size();
    int index = 0;
    for (int i = 0; i < rowsize; i++) {
        double mean, stdev;
        double sum = 0, sq_sum = 0;
        for (int j = 0; j < trainset.size(); j++) {
            sum += trainset[j][i];
            sq_sum += trainset[j][i] * trainset[j][i];
        }
        mean = sum / trainset.size();
        stdev = sqrt(sq_sum / trainset.size() - mean*mean);
        for (int j = 0; j < trainset.size(); j++) {
            trainset[j][i] = (trainset[j][i]-mean)/stdev;
        }
    }

}

double euclideanDistance(vector<double> & lhs, vector<double> & rhs) {
    //euclidean distance function used as a measure to determine similarities between knn's
    double total = 0;
    for (int i = 0; i < (int)lhs.size(); i++) {
        total += (lhs[i] - rhs[i])*(lhs[i] - rhs[i]);
    }
    return sqrt(total);
}

void KnnClassifier::fit(vector<vector<double>> & trainset, vector<int> & label) {
    // trains the dataset by normalizing if the boolean is set
    data = trainset;
    if (normalize) {
        norm(data);
    }
    labels = label;
    cout << "Knn Training completed" << endl;
}

vector<int> KnnClassifier::test(vector<vector<double>> & testset) {
    // performs the actual classifications
    vector<pair<double,int>> distances(data.size());
    vector<int> target(testset.size());
    int index = 0;
    int count = 0;
    if (normalize) {
        norm(testset);
    }
    cout << "It begins..." << endl;
    for (auto & row : testset) {
        for (auto & instance : data) {
            distances[index]=make_pair(euclideanDistance(row, instance),labels[index]);
            index++;
        }
        index = 0;
        //sorting in ascending order so it's easier to classify
        sort(distances.begin(), distances.end(), ascending);
        map<int, int> ht; // used the count the occurances of each label among the k-nearest 
                          // neighbours
        for (int i = 0; i < k; i++) {
            if (ht.find(distances[i].second) == ht.end()) {
                ht.insert(pair<int, int>(distances[i].second, 1));
            }
            else {
                ht[distances[i].second]++;
            }
        }
        int max = INT_MIN;
        int decision=-1;
        for (auto & x : ht) {
            // we take the heighest count label as the 'predicted' label 
            if (x.second > max) {
                max = x.second;
                decision = x.first;
            }
        }
        target[count++] = decision;
        if (count % 1000 == 0) {
            cout << "iteration num " << count << endl;
        }
    }
    // returns the probability
    return target;
}