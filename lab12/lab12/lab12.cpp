#include <iostream>
#include <string>
#include <vector>
#include <memory>
enum class ContactType {
    FRIEND, ACQUAINTANCE,
    COLLEAGUE
};
class Contact {
protected:
    std::string name;
public:
    Contact(const std::string name):name(name){}
    virtual ~Contact() = default;
    virtual ContactType getType()const = 0;
    std::string getName()const {
        return name;
    }
    virtual void printDetails() const{
        std::cout << "Name " << name << '\n';
    }
};
class Friend :public Contact {
    std::string DateOfBirth;
    std::string phone;
    std::string address;
public:
    Friend(const std::string& name, const std::string dob, const std::string phone, const std::string add) :Contact(name), DateOfBirth(dob), phone(phone), address(add) {}
    ContactType getType()const override {
        return ContactType::FRIEND;
    }
    void printDetails()const override {
        Contact::printDetails();
        std::cout << "Data " << DateOfBirth << " phone " << phone << " address " << address<<'\n';
    }
};
    class Acquaintance :public Contact {
        std::string phoneNr;
    public:
        Acquaintance(const std::string& name, const std::string phone) :Contact(name), phoneNr(phone) {}
        ContactType getType()const override {
            return ContactType::ACQUAINTANCE;
        }
        void printDetails()const override {
            Contact::printDetails();
            std::cout << " Acquaintance\n" << " phone " << phoneNr<<'\n';
        }
    };
    class Colleague :public Contact {
        std::string phoneNr;
        std::string company;
        std::string address;
    public:
        Colleague(const std::string &name,const std::string phone,const std::string company,const std::string address):Contact(name),phoneNr(phone),company(company),address(address){}
        ContactType getType()const override {
            return ContactType::COLLEAGUE;
        }
        void printDetails()const override {
            Contact::printDetails();
            std::cout << " Colleague\n" << " phone " << phoneNr<<" company "<<company<<" address "<<address<<'\n';
        }
    };
    class AddressBook {
        std::vector<std::shared_ptr<Contact>>contacts;
    public:
        void addContact(std::shared_ptr<Contact>contact) {
            contacts.push_back(contact);
            std::cout << "contact adaugat " << contact->getName() << '\n';
        }
        std::shared_ptr<Contact>searchbyName(const std::string& name) {
            for (const auto& contact : contacts)
                if (contact->getName() == name)
                    return contact;
            return nullptr;
        }
        void deletebyName(const std::string& name) {
            auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const std::shared_ptr<Contact>&c) { return c->getName() == name; });
            if (it != contacts.end())
                std::cout << "contact sters " << name << '\n';
            else
                std::cout << "nu s a gasit contactul";
        }
        std::vector<std::shared_ptr<Friend>>getFriend() {
            std::vector<std::shared_ptr<Friend>>friends;
            for (const auto& contact : contacts)
                if (contact->getType() == ContactType::FRIEND) {
                    auto friendptr = std::dynamic_pointer_cast<Friend>(contact);
                    if (friendptr)
                        friends.push_back(friendptr);
                }
            return friends;
        }
        void printAll() const {
            for (const auto& contact : contacts)
                contact->printDetails();
        }
    };
int main()
{
    AddressBook myAgenda;
    auto c1 = std::make_shared<Friend>("Ana Popescu", "12/05/1995", "0722222223", "Str.Vasile Lupu");
    auto c2 = std::make_shared<Acquaintance>("Mihai Ionescu", "0744987654");
    auto c3 = std::make_shared<Colleague>("Elena Radu", "0755111222", "Mega", "Piata Unirii");
    auto c4 = std::make_shared<Friend>("Alex Vasile", "30/10/1993", "0766333444", "Str.Palat");

    myAgenda.addContact(c1);
    myAgenda.addContact(c2);
    myAgenda.addContact(c3);
    myAgenda.addContact(c4);

    myAgenda.printAll();

    std::cout << "\nCautare Elena Radu\n";
    auto found = myAgenda.searchbyName("Elena Radu");
    if (found) found->printDetails();
    auto friends = myAgenda.getFriend();
    for (const auto& f : friends) {
        f->printDetails();
        std::cout << "\n";
    }
    std::cout << "Delete\n";
    myAgenda.deletebyName("Mihai Ionescu");
}
