///
/// FileSystem.cpp
///
class FileSystem
{
	public:

		std::size_t numDisks() const;

};

extern FileSystem tfs; // tfs = "the file system"

///
/// Directory.cpp
///
class Directory
{
	public:
		Directory(params);
};

Directory::Directory(params)
{

	std::size_t disks = tfs.numDisks();
}

///
/// Program.cpp
///
	Directory tempDir(params);


// tfs와 tempDir은 다른 번역 단위 안에서 정의된
// 비지역 정적 객체이므로 초기화 순서를 정할 수 없음!
