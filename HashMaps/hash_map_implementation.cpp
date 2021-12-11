#include <iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode {
public:
  MapNode * next;
  string key;
  V value;

  //constructor
  MapNode(string key, V value) {
    this->key = key;
    this->value = value;
    next = NULL;
  }//destructor
  ~MapNode() {
    delete next;
    //recursive
  }
};
template <typename V>
class ourmap {

  MapNode<V>**buckets;
  int count;
  int bucketsize;
public:
  ourmap() {
    count = 0;
    bucketsize = 5;
    buckets = new MapNode<V>*[bucketsize];

    for (int i = 0; i < bucketsize; i++) {
      buckets[i] = NULL;
    }
  }

  ~ourmap() {
    for (int i = 0; i < bucketsize; i++) {
      delete buckets[i];
    }

    delete [] buckets;
  }
  //functions
private:
  //hash functions
  int getBucketIndex(string key) {
    int hashcode = 0;
    int currentCoefficient = 1;
    //base p stuff p = 37
    for (int i = key.length() - 1; i >= 0; i--) {
      hashcode += key[i] * currentCoefficient;
      hashcode = hashcode % bucketsize;

      currentCoefficient *= 37;
      currentCoefficient = currentCoefficient % bucketsize;

    }
    return hashcode % bucketsize;
  }
  void rehash() {
    MapNode<V>** temp = buckets;
    buckets = new MapNode<V>*[2 * bucketsize];

    for (int i = 0; i < 2 * bucketsize; i++) {
      buckets[i] = NULL;
    }

    int oldBucketsize = bucketsize;
    bucketsize *= 2;
    count = 0;

    for (int i = 0; i < oldBucketsize; i++) {
      MapNode<V>* head = temp[i];
      while (head != NULL) {
        string key = head->key;
        V value = head->value;
        insert(key, value); //pointing to the buckets which we changed.
        head = head->next;
      }
    }

    for (int i = 0; i < oldBucketsize; i++) {
      delete temp[i];
    }
    delete [] temp;
  }

public:
  double getLoadFactor(){
    return (1.0*count)/bucketsize;
  }
  int size() {
    return count;
  }

  void insert(string key, V value) {
    int bucketindex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketindex];

    while (head != NULL) {
      if (head->key == key) {
        //updation of existing key in the LL
        head->value = value;
        return;
      }
      head = head->next;
    }
    //separate chaining major step
    head = buckets[bucketindex];
    MapNode<V> * node = new MapNode<V>(key, value);
    node->next = head;
    buckets[bucketindex] = node;
    count++;

    double loadFactor = (1.0 * count) / bucketsize;
    if (loadFactor > 0.7) {
      rehash();
    }
  }

  V remove(string key) {
    int bucketindex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketindex];
    MapNode<V>* prev = NULL;

    while (head != NULL) {
      if (head->key == key) {
        if (prev == NULL) {
          //if node is head
          buckets[bucketindex] = head->next;
        }
        else {
          count--;
          
          prev -> next = head->next;
          head->next = NULL;
          V ans = head->value;
          delete head;
          return ans;
        }
      }

      prev = head;
      head = head->next;
    }

    return 0;
  }

  V getValue(string key) {
    int bucketindex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketindex];

    while (head != NULL) {
      if (head->key == key) {
        return head->value;
      }
      head = head->next;
    }

    return 0;
  }
};


int main() {
  ourmap<int> mpp;

  for (int i = 0; i < 10; i++) {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    int value = i + 1;
    mpp.insert(key, value);
    cout << mpp.getLoadFactor() << endl;
  }

  cout << mpp.size() << endl;
   mpp.remove("abc2");
   mpp.remove("abc7");

  for (int i = 0; i < 10; i++) {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout << key << " : " << mpp.getValue(key) << endl;
  }
  cout << mpp.size() << endl;

  return 0;
}
