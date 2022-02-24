<div id="kl_assignments" class="">
<h3 class="">Module Assignment details</h3>
<strong>Objectives:</strong> Understanding generic programming and information hiding by developing generic containers. Getting familiar with the concept of class template and its usage. Use of nested (iterator) classes. Use of namespace. Operator overloading.<strong>Task:</strong> Implement a doubly-linked list class template List and its associated iterators.</div>
<div class=""><strong>Requirements:</strong>
<ol>
<li>A header file <em>List.h</em> is provided, which contains the interfaces of the doubly linked list class template <em>List</em>. In particular, it contains a nested Node structure, and two nested iterators class (iterator and const_iterator). You cannot change anything in the List.h file.&nbsp; The List.h file is attached to this assignment.&nbsp;</li>
<li>A driver program <em>test_list.cpp</em> has been included. It is an example test program that will run some tests on your implementation of the doubly-linked list class template for different data types . Don't make any changes to this driver program. However, your class will be tested with more than just this sample driver. It is recommended that you write other driver programs of your own, for more thorough testing.</li>
<li>You need to implement the member functions of the doubly-linked list class template List in a file named <em>List.hpp</em>. Note that <em>List.hpp</em> has been #included in the header file List.h (towards the end of the file). As we have discussed in lecture, you should not try to compile <em>List.hpp</em> (or <em>List.h</em>) by themselves. These comprise a header that will be #included into other programs you might write. You need to implement all the member functions of List, List::iterator, and List::const_iterator, and non-class overloaded functions operator==(), operator!=(), and operator&lt;&lt;() included in List.h. The design of the List container follows the one presented in the textbook. It has three member variables, theSize, head, and tail. theSize records the number of elements in the list. The head should point to the first node, the tail should point to a sentinel node (one passed the last data node).&nbsp; &nbsp;An empty list will only contain the sentinel node.&nbsp; Your implementation will contain more features than those in the textbook's implementation. We describe the requirements of each function in the following (this specifications may not write the function signatures in detail, please refer to the List.h file for the detailed function declaration).</li>
</ol>
<strong> Member functions of nested const_iterator class:</strong>
<ul>
<li><span style="text-decoration: underline;"><em>const_iterator()</em></span>: default zero-parameter constructor. Set pointer current to nullptr.&nbsp;</li>
<li><span style="text-decoration: underline;"><em>operator*()</em></span>: returns a reference to the corresponding element in the list by calling retrieve() member function.</li>
<li><span style="text-decoration: underline;"><em>operator++()</em></span>, operator++(int), operator--(), operator--(int): prefix and postfix increment and decrement operators.</li>
<li><span style="text-decoration: underline;"><em>operator==()</em> </span>and operator!=(): two iterators are equal if they refer to the same element.</li>
<li><span style="text-decoration: underline;"><em>retrieve()</em></span>: return a reference to the corresponding element in the list.&nbsp;</li>
<li><span style="text-decoration: underline;"><em> const_iterator(Node *p)</em>:</span> one-parameter constructor. Set pointer current to the given node pointer p.</li>
</ul>
<p>Note:&nbsp; The const_iterator class is designed to access individual nodes with changing them.&nbsp;&nbsp;</p>
<p>&nbsp;</p>
<strong>Member functions of nested iterator class</strong><strong></strong><strong></strong></div>
<ul>
<li><em>iterator()</em><span style="text-decoration: underline;"><em>:</em></span> default zero-parameter constructor.</li>
<li><span style="text-decoration: underline;">operator*()</span>: returns a reference to the corresponding element in the list by calling retrieve() member function.</li>
<li><span style="text-decoration: underline;">operator++()</span>, operator++(int), operator--(), operator--(int): prefix and postfix increment and decrement operators.</li>
<li><span style="text-decoration: underline;">iterator(Node *p)</span>: one-parameter constructor</li>
</ul>
<p>NOte: The iterator class is designed to access individual nodes with the ability to change them.&nbsp;&nbsp;</p>
<p><strong> Member functions of List class template</strong></p>
<ul>
<li><span style="text-decoration: underline;"><em>List()</em></span>: Default zero-parameter constructor. Call init() to initialize list member variables.</li>
<li><span style="text-decoration: underline;"><em>List(const List &amp;rhs)</em></span>: Copy constructor. Create the new list using elements in existing list rhs.</li>
<li><span style="text-decoration: underline;"><em>List(List &amp;&amp;rhs):</em></span> move constructor.</li>
<li><span style="text-decoration: underline;"><em>List(int num, const T &amp; val = T())</em></span>: Construct a list with num elements, all initialized with value val.</li>
<li><span style="text-decoration: underline;"><em>List(const_iterator start, const_iterator end)</em></span>: construct a List with elements from another list between start and end. Including the element referred to by the start iterator, but not the end iterator, that is [start, end).</li>
<li><span style="text-decoration: underline;"><em>List(std::initializer_list iList)</em> </span>: construct a List with elements from the initializer list that is passed in. Note that this will allow declarations like this:</li>
</ul>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <em>&nbsp; List myList {2, 4, 6, 8, 10, 12, 14, 16};</em></p>
<ul>
<li><em><span style="text-decoration: underline;">~List():</span> destructor. You should properly reclaim all dynamically allocated memory. Should call </em>clear().</li>
<li><em><span style="text-decoration: underline;">operator=(List &amp;rhs):</span> copy assignment operator </em></li>
<li><em><span style="text-decoration: underline;">operator=(List &amp;&amp;rhs)</span>: move assignment operator </em></li>
<li><em><span style="text-decoration: underline;">operator=(std::initializer_list iList)</span> : assign the initializer list data to be the calling object's new data. Example call:</em></li>
</ul>
<p><em>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; list2 = {1, 3, 5, 7, 9, 11, 13, 15};</em></p>
<ul>
<li><em><span style="text-decoration: underline;">size()</span>: return the number of elements in the List. </em></li>
<li><em><span style="text-decoration: underline;">empty():</span> return true if no element is in the list; otherwise, return false. </em></li>
<li><em><span style="text-decoration: underline;">clear()</span>: delete all the elements in the list.&nbsp;</em></li>
<li><em><span style="text-decoration: underline;">reverse()</span>: reverse the order of the elements in the list. That is, the original first element becomes the last, while the original last becomes the first. </em></li>
<li><em><span style="text-decoration: underline;">front()</span> and <span style="text-decoration: underline;">back()</span>: return reference to the first and last element in the list, respectively. </em></li>
<li><em><span style="text-decoration: underline;">push_front()</span> and </em><span style="text-decoration: underline;">push_back()</span><em>, insert the new object as the first and last element into the list, respectively; and their move versions. </em></li>
<li><em><span style="text-decoration: underline;">pop_front()</span> and <span style="text-decoration: underline;">pop_back()</span>, delete the first and last element in the list, respectively. </em></li>
<li><em><span style="text-decoration: underline;">remove(const T &amp; val)</span>: delete all nodes with value equal to </em>val <em>from the list. </em></li>
<li><em><span style="text-decoration: underline;">remove_if(PREDICATE pred):</span> delete all nodes for which pred returns true. PREDICATE is a template type, allowing a function object to be passed. (i.e. a true/false condition/function can be passed in via the functor). </em></li>
<li><em><span style="text-decoration: underline;">print(ostream &amp;os, char ofc = ' '):</span> print all elements in the list, using character ofc as the deliminator between elements in the list. </em></li>
<li><em><span style="text-decoration: underline;">begin():</span> return iterator to the first element in the list. It should return the tail on an empty list.&nbsp;&nbsp;</em></li>
<li><em><span style="text-decoration: underline;">end()</span>: return iterator to the end marker of the list (tail).&nbsp; The tail, in this implementation, should not point to a valid record but rather just the end-marker of the list.&nbsp;</em></li>
<li><em><span style="text-decoration: underline;">insert(iterator itr, const T &amp; val):</span> insert value val ahead of the node referred to by itr; and its move version </em></li>
<li><em><span style="text-decoration: underline;">erase(iterator itr)</span>: delete node referred to by itr. The return value is an iterator to the following node. </em></li>
<li><em><span style="text-decoration: underline;">erase(iterator start, iterator end):</span> delete all nodes between start and end (<span style="text-decoration: underline;"><strong>including start but not end),</strong></span> that is, all elements in the range [start, end). </em></li>
<li><em><span style="text-decoration: underline;">init():</span> initialize the member variables of list.&nbsp; Should be an empty list , size=0, with a single node that points to the end marker.&nbsp;</em><em></em></li>
</ul>
<p><strong><em>Non-class functions</em></strong></p>
<ul>
<li><em><span style="text-decoration: underline;">operator==(const List &amp; lhs, const List &amp; rhs):</span> check if two lists contain the same sequence of elements. Two lists are equal if they have the same number of elements and the elements at the corresponding position are equal. </em></li>
<li><em><span style="text-decoration: underline;">operator!=(const List &amp; lhs, const List &amp; rhs)</span>: opposite of operator==(). </em></li>
<li><em><span style="text-decoration: underline;">operator&lt;&lt;(ostream &amp; os, const List &amp; l)</span>: print out all elements in list l by calling List::print() function</em><em></em></li>
</ul>
<ol start="4">
<li><em>Write a makefile for your project, to compile the test_list.cpp driver into an executable called proj2.x. Your program must be able to compile and run on the linprog machines.&nbsp; </em></li>
<li><em>Analyze the worst-case run-time complexities of the member functions reverse() and remove_if(). Give the complexities in the form of Big-O. Your analysis can be informal; however, it must be clearly understandable by others. Name the file containing the complexity analysis as </em><span style="text-decoration: underline;">"analysis.txt".</span></li>
</ol>
<p><strong><span style="text-decoration: underline;">Downloads:&nbsp;</span></strong></p>
<p>Downloads are attached to this assignment blow.&nbsp; &nbsp;The sample output&nbsp;<em>myout.txt&nbsp;</em>should be the exact output you produce when you run the&nbsp;<em>test_list.cpp</em>.</p>
<p><a class="instructure_file_link instructure_scribd_file" title="List.h" href="/courses/191038/files/15329931/download?wrap=1" data-api-endpoint="https://canvas.fsu.edu/api/v1/courses/191038/files/15329931" data-api-returntype="File">List.h</a></p>
<p><a class="instructure_file_link instructure_scribd_file" title="myout.txt" href="/courses/191038/files/15329954/download?wrap=1" data-api-endpoint="https://canvas.fsu.edu/api/v1/courses/191038/files/15329954" data-api-returntype="File">myout.txt</a></p>
<p><a id="8257812" class="instructure_file_link" title="Link" href="/courses/191038/files/15329949/download?wrap=1" target="_blank" data-api-endpoint="https://canvas.fsu.edu/api/v1/courses/191038/files/15329949" data-api-returntype="File">test_list.cpp</a></p>
<p><strong>Submission:&nbsp;</strong></p>
<p>Tar up List.hpp, your makefile, and analysis.txt into a single tar archive and submit online via Canvas, in the "Assignments" section. Use the Assignment 3 link to submit. Make sure you tar your programs correctly. Your compressed tar file should be named in this format, all lowercase:</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; lastname_firstname_p2.gz.tar</p>
<p>&nbsp; &nbsp; &nbsp;Example: My tar zipped file would be: <em>gaitros_david_p2.gz.tar</em></p>
<p>The command to produce this file is(provided you are in the directory where the files exist):</p>
<p><em>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; tar –czvf gaitros_david_p2.gz.tar List.h test_list.cpp myout.txt</em></p></div>

</div>
