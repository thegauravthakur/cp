auto start = std::chrono::high_resolution_clock::now();
// Enter code here
    $END$
auto end = std::chrono::high_resolution_clock::now();

cout << "Elapsed time in nanoseconds : "
     << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
     << " ns" << endl;

cout << "Elapsed time in microseconds : "
     << chrono::duration_cast<chrono::microseconds>(end - start).count()
     << " µs" << endl;

cout << "Elapsed time in milliseconds : "
     << chrono::duration_cast<chrono::milliseconds>(end - start).count()
     << " ms" << endl;

cout << "Elapsed time in seconds : "
     << chrono::duration_cast<chrono::seconds>(end - start).count()
     << " sec";
