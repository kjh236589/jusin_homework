#pragma once
#pragma once

class CObj
{
private:
	int		m_iA;

public:
	void	Set_A(int _iA) { m_iA = _iA; }
	int		Get_A() { return m_iA; }

public:
	void	Draw();		// ¸â¹ö ÇÔ¼ö	
};
