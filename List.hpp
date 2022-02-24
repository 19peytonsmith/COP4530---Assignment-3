//
// List class member functions
//

// *****************************************************************
// * Function Name:  init()                                        *
// * Description:  Initializes member variables                    *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
void List<T>::init() {
    // Initialize member variables
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;

}

// *****************************************************************
// * Function Name:  List()                                        *
// * Description: Default constructor-Initializes member variables *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::List() {
    init(); // Initialize
}

// *****************************************************************
// * Function Name:  List()                                        *
// * Description: Copy constructor - copies elements from rhs      *
// * Parameter Description: const List &rhs - used to copy into    *
// * object's list                                                 *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
List<T>::List(const List &rhs) {
    init(); // Initialize
    // Insert rhs elements into list one-by-one
    for(auto & x : rhs)
        push_back(x);
}

// *****************************************************************
// * Function Name:  List()                                        *
// * Description:  Move constructor - moves over member variables  *
// * Parameter Description: List &&rhs - Used to move over to      *
// * object's list                                                 *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
List<T>::List(List &&rhs) {
    // Move over class member variables
    theSize = rhs.theSize;
    head = rhs.head;
    tail = rhs.tail;
    // Set rhs member variables to 0/nullptrs.
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

// *****************************************************************
// * Function Name:  List()                                        *
// * Description: Inserts val, num amount of times into list       *
// * Parameter Description: int num - # of elements, const T &val  *
// * - value being inserted                                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::List(int num, const T &val) {
    init(); // Initialize list
    // Loop num amount of times and insert val into list
    for(int i = 0; i < num; i++){
        push_back(val);
    }
}

// *****************************************************************
// * Function Name:  List()                                        *
// * Description:  Inserts elements given by iterator positions    *
// * Parameter Description: start - start position to insert       *
// * into list, end - ending position to stop inserting into list  *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::List(List::const_iterator start, List::const_iterator end) {
    init(); // Initialize list
    auto iterator = start;
    // Loop through and insert the elements given by iterator from start to end.
    do{
        push_back(*iterator);
        iterator++;
    }while(iterator != end);
}

// *****************************************************************
// * Function Name: List()                                         *
// * Description:  Copies elements from parameter list             *
// * Parameter Description: iList - used to copy over to list      *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::List(std::initializer_list<T> iList) {
    init(); // Initialize list
    // Loop through iList and insert elements one-by-one
    for(T x : iList) {
        push_back(x);
    }
}

// *****************************************************************
// * Function Name:  ~List()                                       *
// * Description: Destructor - deallocates all memory              *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
List<T>::~List() {
    // Clear elements in list and delete head/tail
    clear();
    delete head;
    delete tail;
}

// *****************************************************************
// * Function Name:  operator=()                                   *
// * Description:  Copy assignment operator -                      *
// * copies rhs's elements                                         *
// * Parameter Description: rhs - used to copy over elements       *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
const List<T> &List<T>::operator=(const List &rhs) {
    // Declare copy of List class as parameter and swap values
    List copy = rhs;
    std::swap( *this, copy);
    return *this;
}

// *****************************************************************
// * Function Name:  operator=()                                   *
// * Description:  Move assignment operator - moves                *
// * rhs's elements over                                           *
// * Parameter Description: rhs - used to move over elements       *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
List<T> &List<T>::operator=(List &&rhs) {
    // Swap for each respective member variable
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
}

// *****************************************************************
// * Function Name:  operator=()                                   *
// * Description:  Assigns iList values to object's list           *
// * Parameter Description: iList - used to copy over to list      *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T> &List<T>::operator=(std::initializer_list<T> iList) {
    init(); // Initialize
    for(T x : iList) {
        push_back(x);
    }
    return *this;
}

// *****************************************************************
// * Function Name: size()                                         *
// * Description:  Returns size of list                            *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
int List<T>::size() const {
    return theSize; // Return size
}

// *****************************************************************
// * Function Name:  empty()                                       *
// * Description:  Returns status of whether list is empty or not  *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
bool List<T>::empty() const {
    return (theSize == 0); // If theSize is 0, then the list is empty, else not
}

// *****************************************************************
// * Function Name:  clear()                                       *
// * Description:  Clears all the elements in list                 *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
void List<T>::clear() {
    // While the list is not empty, remove front value until empty
    while(!empty()){
        pop_front();
    }
}

// *****************************************************************
// * Function Name:  reverse()                                     *
// * Description:  Reverses the nodes in the list                  *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
void List<T>::reverse() {
    // Iterator points to the beginning of the list
    auto iterator = begin();
    List<T> reversedList;
    // Loop through all of the elements in the list
    // Push the values into the reversedList backwards one-by-one
    for(int i = 0; i < theSize; i++){
        reversedList.push_front(*iterator);
        iterator++;
    }
    *this = reversedList;
}

// *****************************************************************
// * Function Name:  front()                                       *
// * Description:  Returns front element in list                   *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
T &List<T>::front() {
    // Return reference to first element in list
    return *begin();
}

// *****************************************************************
// * Function Name:  front()                                       *
// * Description:  Returns front element in list - const ver       *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
const T &List<T>::front() const {
    // Return reference to first element in list
    return *begin();
}

// *****************************************************************
// * Function Name:  back()                                        *
// * Description:  Returns back element in list                    *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
T &List<T>::back() {
    // Return reference to end element in list (-- prefix needed to point to last valid record)
    return *--end();
}

// *****************************************************************
// * Function Name:  back()                                        *
// * Description:  Returns back element in list - const ver        *
// * Parameter Description:   No parameters                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
const T &List<T>::back() const {
    // Return reference to end element in list (-- prefix needed to point to last valid record)
    return *--end();
}

// *****************************************************************
// * Function Name:  push_front()                                  *
// * Description:  Inserts val into front of list                  *
// * Parameter Description: val - used to insert into list         *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
void List<T>::push_front(const T &val) {
    // Insert val to the beginning of the list
    insert(begin(),val);
}

// *****************************************************************
// * Function Name:  push_front()                                  *
// * Description:  Inserts val into front of list - move ver       *
// * Parameter Description: val - used to insert into list         *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
void List<T>::push_front(T &&val) {
    // Insert val to the beginning of the list
    insert(begin(),std::move(val));
}

// *****************************************************************
// * Function Name:  push_back()                                   *
// * Description:  Inserts val into back of list                   *
// * Parameter Description: val - used to insert into list         *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
void List<T>::push_back(const T &val) {
    // Insert val to the end of the list
    insert(end(),val);
}

// *****************************************************************
// * Function Name:  push_back()                                   *
// * Description:  Inserts val into back of list - move ver        *
// * Parameter Description: val - used to insert into list         *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
void List<T>::push_back(T &&val) {
    // Insert val to the end of the list
    insert(end(),std::move(val));
}

// *****************************************************************
// * Function Name:  pop_front()                                   *
// * Description:  Removes front element in list                   *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
void List<T>::pop_front() {
    // Erase first node of the list
    erase(begin());
}

// *****************************************************************
// * Function Name:  pop_back()                                    *
// * Description:  Removes back element in list                    *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
void List<T>::pop_back() {
    // Erase last node of the list (-- prefix needed to point to last valid record)
    erase(--end());
}

// *****************************************************************
// * Function Name:  remove()                                      *
// * Description: Removes all elements with val                    *
// * Parameter Description: val - used to check which elements to  *
// * delete                                                        *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
void List<T>::remove(const T &val) {
    // Define iterator that points to the beginning of the list
    auto iterator = begin();
    // Loop through list and check if the value matches up
    do{
        // If iterator's value == val, erase the associated value
        // Note: erase returns iterator to following node, so no
        // need to increment iterator
        if(iterator.retrieve() == val){
            iterator = erase(iterator);
        }else{ // Else do nothing and increment iterator
            iterator++;
        }
    }while(iterator != end());
}

// *****************************************************************
// * Function Name:  remove_if()                                   *
// * Description: Removes all elements based on predicate          *
// * Parameter Description: predicate - boolean argument used to   *
// * test and remove the corresponding values                      *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
template<typename PREDICATE>
void List<T>::remove_if(PREDICATE pred) {
    // Define iterator that points to the beginning of the list
    auto iterator = begin();
    // Loop through list and check predicate at iterator returns true
    do{
        // If predicate is true for iterator value, erase respective value
        // Note: erase returns iterator to following node, so no
        // need to increment iterator
        if(pred(*iterator)){
            iterator = erase(iterator);
        }else{ // Else do nothing and increment iterator
            iterator++;
        }
    }while(iterator != end());
}

// *****************************************************************
// * Function Name:  print()                                       *
// * Description: Prints out stream of data given some delim       *
// * Parameter Description: os - output stream of data, ofc -      *
// * character delim to separate data                              *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
void List<T>::print(std::ostream &os, char ofc) const {
    // Define iterator that points to the beginning of the list
    auto iterator = begin();
    // Loop through entire list and grab data for each node and shift the iterator.
    for(int i = 0; i<theSize; i++){
        os << iterator.retrieve() << ofc;
        iterator++;
    }
}

// *****************************************************************
// * Function Name:  begin()                                       *
// * Description: Returns beginning element of list                *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::begin() {
    // Returns beginning element of list
    return head->next;
}

// *****************************************************************
// * Function Name:  begin()                                       *
// * Description: Returns beginning element of list - const ver    *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
typename List<T>::const_iterator List<T>::begin() const {
    // Const: Returns beginning element of list
    return head->next;
}

// *****************************************************************
// * Function Name:  end()                                         *
// * Description: Returns ending element of list                   *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::end() {
    // Returns ending element of list
    return tail;
}

// *****************************************************************
// * Function Name:  end()                                         *
// * Description: Returns ending element of list - const ver       *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
typename List<T>::const_iterator List<T>::end() const {
    // Const: Returns ending element of list
    return tail;
}

// *****************************************************************
// * Function Name:  insert()                                      *
// * Description: Inserts val into list position with respect      *
// * to iterator itr                                               *
// * Parameter Description: itr - iterator to decide where to      *
// * insert value, val - actual value being inserted               *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::insert(List::iterator itr, const T &val) {
    // Define new pointer of type node to current value given by iterator
    Node *p = itr.current;
    theSize++; // Increment size
    // Insert value in front of value given by iterator
    return{ p->prev = p->prev->next = new Node{ val, p->prev, p}};
}

// *****************************************************************
// * Function Name:  insert()                                      *
// * Description: Inserts val into list position with respect      *
// * to iterator itr - move ver                                    *
// * Parameter Description: itr - iterator to decide where to      *
// * insert value, val - actual value being inserted               *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::insert(List::iterator itr, T &&val) {
    // Define new pointer of type node to current value given by iterator
    Node *p = itr.current;
    theSize++; // Increment size
    // Insert value in front of value given by iterator
    return{ p->prev = p->prev->next = new Node{ std::move(val), p->prev, p}};
}

// *****************************************************************
// * Function Name:  erase()                                       *
// * Description: Erases value based on iterator itr               *
// * Parameter Description: itr - iterator to decide where to      *
// * delete value                                                  *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::erase(List::iterator itr) {
    // Define new pointer of type node to current value given by iterator
    Node *p = itr.current;
    // Rearrange pointers
    iterator retVal{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p; // Delete node
    theSize--; // Decrement size

    return retVal; // Return iterator to following node
}

// *****************************************************************
// * Function Name:  erase()                                       *
// * Description: Erases values in a range based on iterators      *
// * Parameter Description: start - starting position to begin     *
// * erasing elements, end - ending position to stop erasing       *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::erase(List::iterator start, List::iterator end) {
    // Loop through list from iterator = start to end and erase the elements UP TO end
    for(iterator itr = start; itr != end;){
        itr = erase(itr);
    }
    return end; // Return end iterator
}

//
// Non-class functions
//

// *****************************************************************
// * Function Name:  operator==()                                  *
// * Description:  Checks if two lists are identical               *
// * Parameter Description: lhs - one list, rhs - other list       *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs){
    // Define iterators for each of the lists
    auto iteratorlhs = lhs.begin();
    auto iteratorrhs = rhs.begin();

    // If the sizes don't match return false
    if(lhs.size() != rhs.size())
        return false;
    // Loop through the list and check the values element by element
    do{
        // If the values don't match at any time, return false
        if(*iteratorlhs != *iteratorrhs) {
            return false;
        }
        iteratorlhs++;
        iteratorrhs++;
    }while(iteratorlhs != lhs.end());
    // Once here, then they are the same thus return true
    return true;
}

// *****************************************************************
// * Function Name:  operator!=()                                  *
// * Description:  Checks if two lists are different               *
// * Parameter Description: lhs - one list, rhs - other list       *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs){
    // Returns opposite of == operator
    return !(lhs == rhs);
}

// *****************************************************************
// * Function Name: operator<<()                                   *
// * Description: Prints out stream of data given some delim       *
// * Parameter Description: os - output stream of data, l -        *
// * character delim to separate data                              *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l){
    // Call to print function given the parameters
    l.print(os);

    return os;
}

//
// Const_iterator class member functions
//

// *****************************************************************
// * Function Name: const_iterator()                               *
// * Description: Default constructor - sets current to nullptr    *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::const_iterator::const_iterator() {
    // Set current to nullptr by default
    current = nullptr;
}

// *****************************************************************
// * Function Name: operator*()                                    *
// * Description: Overloads * operator by returning current value  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
const T &List<T>::const_iterator::operator*() const {
    // Return value given by iterator's current value
    return retrieve();
}

// *****************************************************************
// * Function Name: operator++()                                   *
// * Description: Overloads ++ by incrementing iterator - postfix  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
typename List<T>::const_iterator &List<T>::const_iterator::operator++() {
    // Shift pointer to next value
    current = current->next;
    return *this;
}

// *****************************************************************
// * Function Name: operator++()                                   *
// * Description: Overloads ++ by incrementing iterator - prefix   *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
    // Set old as type const_iterator to current value and prefix increment this, returning old value
    const_iterator old = *this;
    ++(*this);
    return old;
}

// *****************************************************************
// * Function Name: operator--()                                   *
// * Description: Overloads -- by decrementing iterator - postfix  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
typename List<T>::const_iterator &List<T>::const_iterator::operator--() {
    // Shift pointer to previous value
    current = current->prev;
    return *this;
}

// *****************************************************************
// * Function Name: operator--()                                   *
// * Description: Overloads -- by decrementing iterator - prefix  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
    // Set old as const_iterator to current value and prefix decrement this, returning old value
    const_iterator old = *this;
    --(*this);
    return old;
}

// *****************************************************************
// * Function Name:  operator==()                                  *
// * Description:  Checks if two iterators are equal               *
// * Parameter Description: rhs - used to compare objects iterator *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
bool List<T>::const_iterator::operator==(const List::const_iterator &rhs) const {
    // Returns boolean value if parameter's value equates to list's current value
    return (current == rhs.current);
}

// *****************************************************************
// * Function Name:  operator!=()                                  *
// * Description:  Checks if two iterators are not equal           *
// * Parameter Description: rhs - used to compare objects iterator *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
bool List<T>::const_iterator::operator!=(const List::const_iterator &rhs) const {
    // Returns boolean value if parameter's value does not equate to list's current value
    return (current != rhs.current);
}

// *****************************************************************
// * Function Name:  retrieve()                                    *
// * Description:  Returns current element given by iterator       *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
T &List<T>::const_iterator::retrieve() const {
    return (current->data);
}

// *****************************************************************
// * Function Name:  const_iterator()                              *
// * Description:  Parametrized constructor - sets p to current    *
// * iterator                                                      *
// * Parameter Description: p - node pointer used to set current   *
// * iterator                                                      *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::const_iterator::const_iterator(List::Node *p) {
    current = p;
}

//
// iterator class member functions
//

// *****************************************************************
// * Function Name: iterator()                                     *
// * Description: Default constructor - sets current to nullptr    *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::iterator::iterator() {
    // Set current to nullptr by default
    this->current = nullptr;
}

// *****************************************************************
// * Function Name: operator*()                                    *
// * Description: Overloads * operator by returning current value  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
T &List<T>::iterator::operator*() {
    // Return reference to value given by iterator
    return const_iterator::retrieve();
}

// *****************************************************************
// * Function Name: operator*()                                    *
// * Description: Overloads * operator by returning current value  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
const T &List<T>::iterator::operator*() const {
    // Call to operator* function and return value
    return const_iterator::operator*();
}

// *****************************************************************
// * Function Name: operator++()                                   *
// * Description: Overloads ++ by incrementing iterator - postfix  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator &List<T>::iterator::operator++() {
    // Shift the this pointer to next node
    this->current = this->current->next;
    return *this;
}

// *****************************************************************
// * Function Name: operator++()                                   *
// * Description: Overloads ++ by incrementing iterator - prefix   *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    // Set old as type iterator to current value *this and prefix increment this, returning old value
    iterator old = *this;
    ++(*this);
    return old;
}

// *****************************************************************
// * Function Name: operator--()                                   *
// * Description: Overloads -- by decrementing iterator - postfix  *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator &List<T>::iterator::operator--() {
    // Shift the this pointer to previous node
    this->current = this->current->prev;
    return *this;
}

// *****************************************************************
// * Function Name: operator--()                                   *
// * Description: Overloads -- by decrementing iterator - prefix   *
// * Parameter Description: No parameters                          *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Textbook                                          *
// *****************************************************************
template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
    // Set old as type iterator to current value *this and prefix decrement this, returning old value
    iterator old = *this;
    --(*this);
    return old;
}

// *****************************************************************
// * Function Name:  iterator()                                    *
// * Description:  Parametrized constructor - sets p to current    *
// * iterator                                                      *
// * Parameter Description: p - node pointer used to set current   *
// * iterator                                                      *
// * Date:  01/28/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: None                                              *
// *****************************************************************
template<typename T>
List<T>::iterator::iterator(List::Node *p){
    // Set current pointer to parameter value
    this->current = p;
}