#include <bits/stdc++.h>

void pairs(){
    std::pair<int, int> p = {23, 14};
    std::pair<int, int> pair_array[5];

    for (int i = 0; i < 5; ++i){
        std::cin >> pair_array[i].first;
        std::cin >> pair_array[i].second;
    }

    for (int k = 0; k < 5; ++k){
        std::cout << pair_array[k].first << " " << pair_array[k].second << std::endl;
    }
}

void vectors(){
    std::vector<int> v;

    v.push_back(1); // adds 1 to the vector v
    v.emplace_back(2); // same thing as push_back but a bit faster, also
                       // is easier to use in terms of syntax, will see later
    v.emplace_back(3);

    // for (int i = 0; i < 3; ++i){
    //     std::cout << v[i] << " ";
    // }
    // std::cout << "\n";

    // A vector of pairs

    std::vector<std::pair<int, int>> vector_of_pairs;

    vector_of_pairs.push_back({10, 01});

    // std::cout << vector_of_pairs[0].first << " " << vector_of_pairs[0].second << std::endl;

    vector_of_pairs.emplace_back(40, 04);

    // std::cout << vector_of_pairs[1].first << " " << vector_of_pairs[1].second << std::endl;

    std::vector<int> v0(5); // declares a vector v of size 5, but more can be stored.

    std::vector<int> v1(5, 7); // declares a vector v1 of size 5, where each elements
                               // stores 7 --> {7, 7, 7, 7, 7}

    // for (int i = 0; i < 5; ++i){
    //     std::cout << i+1 << ". element of v1 is " << v1[i] << "\n";
    // }

    // std::vector<int> v2(v1);  // v2 now contains v1

    // for (int i = 0; i < 5; ++i){
    //     std::cout << i+1 << ". element of v2 is " << v2[i] << "\n";
    // }

    // Printing vectors through iterators

    // std::vector<int>::iterator it = v1.begin();
    // //++it;
    // std::cout << *(it) << "\n";

    // std::vector<int>::iterator it1 = v1.end(); // points to the memory address after the last element
    // --it1;
    // std::cout << *(it1) << std::endl; //

    // std::vector<int>::iterator it2 = v1.rend(); // nobody uses this anymore, but theoretically it will point to the element before the first element in the vector
    // it2++;
    // std::cout << *(it2) << std::endl;

    // std::vector<int>::iterator it3 = v1.rbegin();
    // it3++;
    // std::cout << *(it3) << std::endl;
    v1.push_back(6);
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
    //     std::cout << *(it) << " ";
    // }
    // std::cout << std::endl;

    // for (auto it = v.begin(); it != v.end(); ++it){
    //     std::cout << *(it) << " ";
    // }
    // std::cout << std::endl;

    // for (auto it : v1){
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;

    // Erase function

    //v1.erase(v1.end()-1); // deletes the element at that position

    //v1.erase(v1.begin(), v1.end()-1); // deletes the elements from [start, end) <-- all from start to end-1

    // for (auto it : v1){
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;

    v.insert(v.begin(), 0);

    for (auto it = v.begin(); it != v.end(); ++it){
        std::cout << *(it) << " ";
    }
    std::cout << std::endl;

    v1.insert(v1.begin() + 2, v.begin(), v.end());

    for (auto it : v1){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    v1.insert(v1.begin() + 4, 2, 5);

    for (auto it : v1){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "The size of vector v1 is " << v1.size() << std::endl;

    v1.pop_back();

    for (auto it : v1){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    v1.swap(v);

    for (auto it : v){
        std::cout << it << " ";
    }

    std::cout << std::endl;

    for (auto it : v1){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    v1.clear();

    std::cout << "Vector v1 is " << v1.empty() << std::endl << "Vector v is " << v.empty() << std::endl;

}
void lists(){
    std::list <int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);
    // rest of the functions are the same as for vectors
}
void deque(){
    std::deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);
    // rest of the functions are the same as for vectors
}
void stack(){
    std::stack<int> st;
    st.push(1);
    st.pop();
    std::cout << "The size of the stack is " << st.size() << std::endl;
    std::cout << "The top of the stack is " << st.top() << std::endl;
    std::cout << "Is the stack empty? " << st.empty() << std::endl;
    std::stack<int> st1;
    st1.push(0);
    st1.swap(st);
}
void queue(){
    std::queue<int> q;
    q.push(1);
    q.emplace(2);
    q.push(5);
    std::cout << "The front of the queue is " << q.front() << std::endl;
    q.pop();
    q.back() += 5;
    std::cout << "front of queue: " << q.front() << std::endl;
    std::cout << "back of queue: " << q.back() << std::endl;
}
int main(){
    // std::string s = "Shokalskiy";
    // int len = s.size();
    // std::cout << s[len-1] << std::endl;
    // char c;
    // std::cin >> c;

    // switch(c){
    //     case 'a':
    //         std::cout << "Vowel\n";
    //         break;
    //     case 'e':
    //         std::cout << "Vowel\n";
    //         break;
    //     case 'i':
    //         std::cout << "Vowel\n";
    //         break;
    //     case 'o':
    //         std::cout << "Vowel\n";
    //         break;
    //     case 'u':
    //         std::cout << "Vowel\n";
    //         break;
    //     default:
    //         std::cout << "Consonant\n";
    // }

    // for (int i = 1; i <= 5; ++i){
    //     std::cout << "Hi. Count: " << i << "\n";
    // }

    // int j = 0;
    // while (j <= 5){
    //     std::cout << "Countdown: " << 5-j << std::endl;
    //     j = j + 1;
    // }

    // int j = 0;
    // do{
    //     std::cout << "Less than 5, you are " << j << std::endl;
    //     j = j + 1;
    // } while (j < 5);
    vectors();
    return 0;
}
