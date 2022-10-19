// code for transforming 'string to number' && 'number to string';

string num_str_num()
{
    // 'string to number' transform...
    stringstream p(given_string);
    ll number = 0;
    p >> number;
    cout << number << "\n";

    // 'number to string' transform...
    stringstream s;
    s << given_number;
    str = s.str();
    cout << str << "\n";
}
