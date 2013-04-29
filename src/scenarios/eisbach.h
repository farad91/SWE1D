/**
 * @file
 *  This file is part of SWE1D
 *
 *  SWE1D is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SWE1D is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SWE1D.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Diese Datei ist Teil von SWE1D.
 *
 *  SWE1D ist Freie Software: Sie koennen es unter den Bedingungen
 *  der GNU General Public License, wie von der Free Software Foundation,
 *  Version 3 der Lizenz oder (nach Ihrer Option) jeder spaeteren
 *  veroeffentlichten Version, weiterverbreiten und/oder modifizieren.
 *
 *  SWE1D wird in der Hoffnung, dass es nuetzlich sein wird, aber
 *  OHNE JEDE GEWAEHELEISTUNG, bereitgestellt; sogar ohne die implizite
 *  Gewaehrleistung der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN
 *  ZWECK. Siehe die GNU General Public License fuer weitere Details.
 *
 *  Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
 *  Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 * 
 * @copyright 2013 Technische Universitaet Muenchen
 * @author Sebastian Rettenberger <rettenbs@in.tum.de>
 * @author Raphael Dümig <duemig@in.tum.de>
 */

#ifndef SCENARIOS_DAMBREAK_H_
#define SCENARIOS_DAMBREAK_H_

#include "types.h"

namespace scenarios
{

class Eisbach
{
private:
	/** Number of cells */
	const unsigned int m_size;
        const unsigned int m_wall_pos;
        const float m_wall_height;
        const unsigned int m_wall_width;

public:
	Eisbach(unsigned int size)
		: m_size(size),
		  m_wall_pos(size/2),
		  m_wall_height(0.5),
		  m_wall_width(size/50)
	{
	}

	/**
	 * @return Initial water height at pos
	 */
	float getHeight(unsigned int pos)
	{
		if (pos - m_wall_pos >= 0 && pos - m_wall_pos < m_wall_width)
			return 1.0 - m_wall_height;

		return 1.0;
	}
	
	/**
	 * @return Initial momentum at pos
	 */
	float getMomentum(unsigned int pos)
	{
            if (pos - m_wall_pos >= 0 && pos - m_wall_pos < m_wall_width)
                return 2.5;
            
            return 5.0;
	}
	
	/**
         * @return floor elevation at pos
         */
	float getBathymetry(unsigned int pos)
        {
            if (pos - m_wall_pos >= 0 && pos - m_wall_pos < m_wall_width)
                return m_wall_height;
            
            return 0.0;
        }
        
	/**
	 * @return Cell size of one cell (= domain size/number of cells)
	 */
	T getCellSize()
	{
		return 100.f / m_size;
	}
};

}

#endif /* SCENARIOS_DAMBREAK_H_ */
