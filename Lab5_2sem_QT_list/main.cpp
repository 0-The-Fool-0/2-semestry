#include <QCoreApplication>
#include <QList>
#include <QVector>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <QtAlgorithms>
#include <QBitArray>
#include <bitset>
#include <iostream>
#include <iterator>
#include <QtEndian>
    using namespace std;
// ---- replace_all ----
template<typename T>
void replace_all(QList<int> &list, const T &oldVal, const T &newVal) {
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == oldVal)
            list[i] = newVal;
    }
}

void printList(const QList<int>& lst) {
    QStringList result;
    for (int num : lst ) {
        result.append(QString :: number(num));
    }
    qDebug() << "Spisok:" << result.join(" ");
}

void deleteElements(QList<int>& lst, int position, int count) {
    if (position >=0 && position < lst.size()) {
        lst.erase(lst.begin() + position, lst.begin() + qMin(position + count, lst.size()));
    }
}

void insertElements(QList<int>& lst, int position, const QVector<int>& elements) {
    if ( position >= 0 && position <= lst.size()) {
        for ( int num : elements) {
            lst.insert(position++, num);
        }
    }
}

bool searchSubsequence(const QList<int>& lst, const QVector<int>& pattern) {
    QVector<int> squares;
    transform(pattern.begin(), pattern.end(), back_inserter(squares), [](int n) { return n*n;});
    return search(lst.begin(), lst.end(), squares.begin(), squares.end()) != lst.end();
}

QVector<int>::iterator findSortedRange(QList<int>& lst) {
    return is_sorted_until(lst.begin(), lst.end());
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QList<int> myList = { 1, 1, 4, 9, 16, 25, 49, 64, 81, 100 };
    QVector<int> array = { 2, 3, 4 };
    int choice, pos, count;


    do{
        qDebug() << "Menu:";
        qDebug() << "1. Prosmotret sostoyanie spiska";
        qDebug() << "2. Udalit neskolko elementov s zadannoy pozizzii";
        qDebug() << "3. Dobavit neskolko elementov v zadannuu posiziu s massiva";
        qDebug() << "4. Dobavit neskolko elementov iz massiva";
        qDebug() << "5. Nayti v massive zelyh chisel posled, kagdyy element kotoroy raven kvadratu drugogo massiva";
        qDebug() << "6. Poisk naibolchego otsortirovannogo diapazona";
        qDebug() << "7. baytovye preabrozavaniya";
        qDebug() << "8. zamena";
        qDebug() << "9. Vyhod iz programmy";
        qDebug() << "Vvedite vash vybor: ";
        cin >> choice;

        switch (choice) {
        case 1:{
            printList(myList);
            break;}
        case 2:{
            qDebug() << "Vvedite pozizziu dlya udaleniya: ";
            cin >> pos;
            qDebug() << "Vvedite kolichestvo elementov dlya udaleniya: ";
            cin >> count;
            deleteElements(myList, pos-1, count);
            break;}
        case 3:{
            qDebug() << "Vvedite pozizziu dlya vstavki: ";
            cin>> pos;
            insertElements(myList, pos-1, array);
            break;}
        case 4:{
            myList.append(array.toList());
            break;}
        case 5:{
            if (searchSubsequence(myList, array)) {
                qDebug() << "Podposledovatelnost naydena.\n";
            }
            else {
                qDebug() << "Podposledovatelnost ne naydena.\n";
            }
            break;
        }
        case 6: {
            auto maxSegmentBegin = myList.begin();
            auto maxSegmentEnd = myList.begin();
            int maxLength = 0;
            for (auto it = myList.begin(); it != myList.end();) {
                auto segmentEnd = is_sorted_until(it, myList.end());
                int currentLength = std::distance(it, segmentEnd);
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    maxSegmentBegin = it;
                    maxSegmentEnd = segmentEnd;
                }
                it = segmentEnd;
            }

            qDebug() << " ";
            for (auto iter = maxSegmentBegin; iter != maxSegmentEnd; ++iter) {
                qDebug() << *iter;
            }
            break;
        }

        case 7:
        {
            QList<quint8> list8;
            qDebug() << "list befor preobrazovaniy : " << "\n";
            for (int i = 0; i < myList.size(); i++) {
                if (myList[i]>0 && myList[i]<256) {
                    list8.push_back(myList[i]);
                }
                cout << myList[i] << "\n";
            }
            qDebug() << "list after magic : " << "\n";
            for (int i = 0; i < list8.size(); i++) {
                cout << "element : "<< (int)list8[i] << " amount of leading zero bits : "
                     << qCountLeadingZeroBits(list8[i]) << " for checking : " << bitset<8>(list8[i])<<"\n";
            }
            break;
        }
        case 8: {
            int a, b;
            cout << "elements what you want to replace: ";
              cin >> a;
            cout << "elements to what you want to replace: ";
                  cin >> b;
            replace_all(myList, static_cast<quint8>(a), static_cast<quint8>(b));
            qDebug() << "\nAfter replace_all:";
            for (auto it= myList.begin(); it!=myList.end(); it++) {
                qDebug() << QString::number(*it, 16);
            }
            break;
        }
        case 9:
            return 0;
        default:
            qDebug() << "Nevernyy vybor. Poprobuyte eche raz.\n";
            break;
        }
    }while(choice!=9);
    return 0;
}
