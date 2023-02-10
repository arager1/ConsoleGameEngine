

#include <string>
#include <memory>
#include <map>
#include <fstream>


namespace Serial
{


class ClassInfo
{
public:
    ClassInfo(const std::string& name, int version = 0) :
        m_name{name}, m_version{version} {}
    const std::string& getName() const { return m_name; }
    int getVersion() const { return m_version; }
private:
    const std::string m_name {};
    const int m_version {};
};


class Instantiatable
{
public:
    virtual ~Instantiatable() {}
    virtual ClassInfo getClassInfo() const = 0;

private:
};



class ObjectFactory
{
public:

    static ObjectFactory& instance();

    template<typename ClassType> // Requires ClassType : Instantiatable
    void registerClass(const std::string& className);

    std::unique_ptr<Instantiatable> createClass(const std::string& className);

private:
    ObjectFactory() = default;
    ObjectFactory(const ObjectFactory&) = delete;
	ObjectFactory(ObjectFactory&&) = delete;
	ObjectFactory& operator=(const ObjectFactory&) = delete;
	ObjectFactory& operator=(ObjectFactory&&) = delete;
	~ObjectFactory() = default;
    
    std::map<std::string, std::function<std::unique_ptr<Instantiatable>()>> m_factory {};
};


class Formatter
{
public:
    virtual ~Formatter() {}

    virtual std::string formatClassInfo(const ClassInfo& classInfo) const = 0;
    virtual ClassInfo unformatClassInfo(const std::string& str) const = 0;
    virtual std::string formatValue(const std::string val) const = 0;
    virtual std::string unformatValue(std::string str) const = 0;

private:

};


class XmlFormatter : public Formatter
{
public:
    virtual std::string formatClassInfo(const ClassInfo& classInfo) const override
    {
        return "<Object class=\"" + classInfo.getName() + "\" version=\"" + std::to_string(classInfo.getVersion()) + "\">";
    }
    
    virtual ClassInfo unformatClassInfo(const std::string& str) const override
    {
        int nameBegin { str.find("\"", str.find("=", str.find("class"))) + 1 };
        int versionBegin { str.find("\"", str.find("=", str.find("version"))) + 1 };
        return ClassInfo
        {
            str.substr(nameBegin, str.find("\"", nameBegin) - nameBegin),
            std::stoi(str.substr(versionBegin, str.find("\"", versionBegin) - versionBegin))
        };
    }

    virtual std::string formatValue(const std::string val) const override
    {
        return "<Value>" + val + "</Value>";
    }

    virtual std::string unformatValue(std::string str) const
    {
        int valueBegin { str.find(">", str.find("<Value")) + 1 };
        return str.substr(valueBegin, str.find("</Value>", valueBegin) - valueBegin);
    }

private:

};


class Archive
{
public:
    virtual ~Archive() {}

    // ????????????????????????????????????????????????????????????? //
    Archive& operator<<(const Persistent& persistent)
    {
        persistent.store(*this);
        return *this;
    }
    Archive& operator>>(Persistent& persistent)
    {
        persistent = Persistent::load(*this);
        return *this;
    }
    // ????????????????????????????????????????????????????????????? //

    Archive& operator<<(const std::string& str)
    {
        write(preMeta());
        write(str);
        write(postMeta());
        return *this;
    }

    Archive& operator>>(std::string& str)
    {
        read(str);
        return *this;
    }

    Archive& operator<<(int n)
    {
        return (*this) << std::to_string(n);
    }
    Archive& operator>>(int& n)
    {
        std::string str {};
        (*this) >> str;
        n = std::stoi(str);
        return *this;
    }

protected:
    virtual void write(const std::string& str) = 0;
    virtual void read(std::string&) = 0;

    virtual std::string preMeta() = 0;
    virtual std::string postMeta() = 0;


private:

};


class StreamArchive : public Archive
{
public:
    StreamArchive(std::unique_ptr<std::iostream> stream) : m_iostream {std::move(stream)} {}

    virtual ~StreamArchive() {}

    virtual void write(const std::string& str) override
    {
        (*m_iostream) << str;
    }

    virtual void read(std::string& str) override
    {
        (*m_iostream) >> str;
    }

private:
    std::unique_ptr<std::iostream> m_iostream {};
};



class XmlFileArchive : public StreamArchive
{
public:
    XmlFileArchive(std::string filename) : StreamArchive {std::move(std::make_unique<std::fstream>(filename))}
    {
        // File exception logic here
    }

private:

};


class Persistent : public Instantiatable
{
public:
    virtual ~Persistent();

    static std::unique_ptr<Persistent> load(Archive& archive);

    void store(Archive& archive) const
    {

    }

protected:
    virtual void serialize(Archive& archive) = 0;

private:

};


}