#include <iostream>
#include <memory>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#endif

#include "transformer.h"
#include "relations.h"
#include "listnode.h"

void setupUkrainianLocale()
{
    std::setlocale(LC_ALL, "uk_UA.UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}
void editTransformerInteractive()
{
    std::cout << u8"\n=== Створення та редагування трансформатора ===\n";

    double k, u1, p;

    std::cout << u8"Введіть коефіцієнт трансформації k: ";
    std::cin >> k;

    std::cout << u8"Введіть первинну напругу U1 (В): ";
    std::cin >> u1;

    std::cout << u8"Введіть потужність P (Вт): ";
    std::cin >> p;

    Transformer t(k, u1, p);

    std::cout << u8"\nСтворено трансформатор:\n";
    t.printInfo();

    std::cout << u8"\nБажаєте змінити параметри? (1 – так, 0 – ні): ";
    int choice;
    std::cin >> choice;

    while (choice == 1)
    {
        int param;
        std::cout << u8"\nЩо змінити?\n";
        std::cout << u8"1 – коефіцієнт трансформації\n";
        std::cout << u8"2 – первинну напругу\n";
        std::cout << u8"3 – потужність\n";
        std::cout << u8"Ваш вибір: ";
        std::cin >> param;

        if (param == 1) {
            std::cout << u8"Нове значення k: ";
            std::cin >> k;
            t.setTransformationRatio(k);
        }
        else if (param == 2) {
            std::cout << u8"Нова напруга U1: ";
            std::cin >> u1;
            t.setPrimaryVoltage(u1);
        }
        else if (param == 3) {
            std::cout << u8"Нова потужність P: ";
            std::cin >> p;
            t.setPower(p);
        }
        else {
            std::cout << u8"Невірний вибір.\n";
        }

        std::cout << u8"\nОновлений трансформатор:\n";
        t.printInfo();

        std::cout << u8"\nЗмінити ще раз? (1 – так, 0 – ні): ";
        std::cin >> choice;
    }

    std::cout << u8"\nРедагування завершено.\n";
}
void demoUniquePtr()
{
    std::cout << u8"\n=== Демонстрація std::unique_ptr ===\n";

    std::unique_ptr<Transformer> t1 =
        std::make_unique<Transformer>(10.0, 220.0, 100.0);

    std::unique_ptr<Transformer> t2 = std::move(t1);

    std::cout << u8"t1 = " << t1.get() << u8" t2 = " << t2.get() << "\n";
}

void demoSharedPtr()
{
    std::cout << u8"\n=== Демонстрація std::shared_ptr ===\n";

    auto t1 = std::make_shared<Transformer>(20.0, 110.0, 200.0);
    auto t2 = t1;
    auto t3 = t1;

    std::cout << u8"Кількість посилань: " << t1.use_count() << "\n";
}
void demoWeakPtr()
{
    std::cout << u8"\n=== Демонстрація weak_ptr ===\n";

    auto p = std::make_shared<Primary>("A");
    auto s = std::make_shared<Secondary>("B");

    p->secondary = s;
    s->primary = p;

    std::cout << u8"Посилань на Primary: " << p.use_count() << "\n";
    std::cout << u8"Посилань на Secondary: " << s.use_count() << "\n";
}
std::shared_ptr<ListNode> createList()
{
    auto n1 = std::make_shared<ListNode>(Transformer(5, 220, 50));
    auto n2 = std::make_shared<ListNode>(Transformer(10, 220, 100));
    auto n3 = std::make_shared<ListNode>(Transformer(20, 380, 500));

    n1->next = n2;
    n2->next = n3;
    n2->prev = n1;
    n3->prev = n2;

    return n1;
}

void traverseForward(std::shared_ptr<ListNode> node)
{
    while (node)
    {
        node->getTransformer().printInfo();
        node = node->next;
    }
}

void traverseBackward(std::shared_ptr<ListNode> head)
{
    auto tail = head;
    while (tail->next) tail = tail->next;

    while (tail)
    {
        tail->getTransformer().printInfo();
        tail = tail->prev.lock();
    }
}

int main()
{
    setupUkrainianLocale();

    editTransformerInteractive();

    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtr();

    auto head = createList();
    traverseForward(head);
    traverseBackward(head);

    return 0;
}
