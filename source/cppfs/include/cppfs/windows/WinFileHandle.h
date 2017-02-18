
#pragma once


#include <memory>

#include <cppfs/AbstractFileHandleBackend.h>


namespace cppfs
{


class WinFileSystem;


/**
*  @brief
*    File handle for the local file system
*/
class CPPFS_API WinFileHandle : public AbstractFileHandleBackend
{
public:
    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] fs
    *    File system that created this handle
    *  @param[in] path
    *    Path to file or directory
    */
    WinFileHandle(std::shared_ptr<WinFileSystem> fs, const std::string & path);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~WinFileHandle();

    // Virtual AbstractFileHandleBackend functions
    virtual AbstractFileHandleBackend * clone() const override;
    virtual AbstractFileSystem * fs() const override;
    virtual void updateFileInfo() override;
    virtual std::string path() const override;
    virtual bool exists() const override;
    virtual bool isFile() const override;
    virtual bool isDirectory() const override;
    virtual std::vector<std::string> listFiles() const override;
    virtual AbstractFileIteratorBackend * begin() const override;
    virtual unsigned int size() const override;
    virtual unsigned int accessTime() const override;
    virtual unsigned int modificationTime() const override;
    virtual unsigned int userId() const override;
    virtual void setUserId(unsigned int uid) override;
    virtual unsigned int groupId() const override;
    virtual void setGroupId(unsigned int gid) override;
    virtual unsigned long permissions() const override;
    virtual void setPermissions(unsigned long permissions) override;
    virtual bool makeDirectory() override;
    virtual bool removeDirectory() override;
    virtual bool copy(AbstractFileHandleBackend * dest) override;
    virtual bool move(AbstractFileHandleBackend * dest) override;
    virtual bool rename(const std::string & filename) override;
    virtual bool remove() override;
    virtual std::istream * createInputStream(std::ios_base::openmode mode) const override;
    virtual std::ostream * createOutputStream(std::ios_base::openmode mode) override;


protected:
    void readFileInfo() const;


protected:
    std::shared_ptr<WinFileSystem>   m_fs;       ///< File system that created this handle
    std::string                      m_path;     ///< Path to file or directory
    mutable void                   * m_fileInfo; ///< Information about the current file (created on demand)
};


} // namespace cppfs
