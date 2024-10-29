#include <iostream>
#include <cmath>
#include <limits>
#include <bits/stdc++.h> 

// Define a factorial function
double factorial(int n) {
    if (n <= 1) return 1;
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Define the formula as a function
double calculatePi(int terms, double lambda) {
    double pi = 4.0;
    
    for (int n = 1; n <= terms; ++n) {
        // Calculate factorial of n
        double fact_n = factorial(n);
        
        // Calculate the first part of the term
        double part1 = 1.0 / fact_n;
        
        // Calculate the second part of the term
        double part2 = (1.0 / (n + lambda)) - (4.0 / (2 * n + 1));
        
        // Calculate the third part of the term
        double part3_base = ((2 * n + 1) * (2 * n + 1)) / (4.0 * (n + lambda)) - n;
        double part3 = pow(part3_base, n - 1);
        
        // Add the term to pi
        pi += part1 * part2 * part3;
    }
    
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int terms; // Number of terms for approximation
    std::cout<<"Write the number of terms"<<'\n';
    std::cin >> terms;
    double lambda; // Set lambda (The suggested value is 1.0)
    std::cout<<"Set a value for lambda"<<'\n';
    std::cin >> lambda;
    
    // Calculate pi
    double pi_approx = calculatePi(terms, lambda);
    
    // Print the result
    std::cout.precision(std::numeric_limits<double>::digits10 + 1);
    std::cout << "Approximate value of pi: " << pi_approx << std::endl;
    
    return 0;
}