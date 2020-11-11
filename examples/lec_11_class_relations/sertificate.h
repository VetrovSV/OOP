#ifndef SERTIFICATE_H
#define SERTIFICATE_H
#include <string>

/* Документ описывающий образование человека
 * */
class Sertificate
{
    std::string id;  // номер документа
    std::string name, fname, middle_name;
    std::string qualification;  // квалификация
    // TODO: ещё поля?
    // TODO: добавить проверку предусловий

public:
    Sertificate();
    std::string getId() const;
    void setId(const std::string &value);
    std::string getName() const;
    void setName(const std::string &value);
    std::string getFname() const;
    void setFname(const std::string &value);
    std::string getMiddle_name() const;
    void setMiddle_name(const std::string &value);
    std::string getQualification() const;
    void setQualification(const std::string &value);
};

#endif // SERTIFICATE_H
