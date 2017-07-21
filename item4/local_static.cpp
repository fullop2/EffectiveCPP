/* 비지역 정적 객체의 문제를 해결하기 위해 객체를 맡는
 * 함수를 하나 준비하고 그 안에 정적 객체를 넣는다
 * 그리고 그 정적 객체에 대한 참조자를 반환하게 만든다
 * Singleton Pattern의 구현 방식
 */

///
/// FileSystem.cpp
///
class FileSystem {};

FileSystem tfs()
{
	static FileSystem fs;
	return fs;
}

///
/// Directory.cpp
///
class Directory {};

Directory::Directory(params)
{
	std::size_t disks = tfs().numDisks();
}

Directory& tempDir()
{
	static Directory td;
	return td;
}

// 주의 : 멀티스레드 환경에서는 문제를 일으킴!
