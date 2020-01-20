#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

const int T_S = 200;
class HashTableEntry {
   public:
      int k;
      int v;
      HashTableEntry(int k, int v) {
         this->k= k;
         this->v = v;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int k) {
         return k % T_S;
      }
      void Insert(int k, int v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, v);
      }
      int SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return -1;
         else
            return t[h]->v;
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            std::cout<<"No Element found at key "<<k<<std::endl;
            return;
         } else {
            delete t[h];
         }
         std::cout<<"Element Deleted"<<std::endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
int main() {
   HashMapTable hash;
   int k, v;
   int c;
   while (1) {
      std::cout<<"1.Insert element into the table"<<std::endl;
      std::cout<<"2.Search element from the key"<<std::endl;
      std::cout<<"3.Delete element at a key"<<std::endl;
      std::cout<<"4.Exit"<<std::endl;
      std::cout<<"Enter your choice: ";
      std::cin>>c;
      switch(c) {
         case 1:
            std::cout<<"Enter element to be inserted: ";
            std::cin>>v;
            std::cout<<"Enter key at which element to be inserted: ";
            std::cin>>k;
            hash.Insert(k, v);
         break;
         case 2:
            std::cout<<"Enter key of the element to be searched: ";
            std::cin>>k;
            if (hash.SearchKey(k) == -1) {
               std::cout<<"No element found at key "<<k<<std::endl;
               continue;
            } else {
               std::cout<<"Element at key "<<k<<" : ";
               std::cout<<hash.SearchKey(k)<<std::endl;
            }
         break;
         case 3:
            std::cout<<"Enter key of the element to be deleted: ";
            std::cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            std::cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}
