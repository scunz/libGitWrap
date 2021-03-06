/*
 * MacGitver
 * Copyright (C) 2012 Sascha Cunz <sascha@babbelbox.org>
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the
 * GNU General Public License (Version 2) as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program; if
 * not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GIT_OBJECT_TREE_H
#define GIT_OBJECT_TREE_H

#include "GitWrap.h"
#include "ObjectId.h"
#include "Object.h"
#include "TreeEntry.h"

namespace Git
{

	class DiffList;

	/**
	 * @ingroup		GitWrap
	 * @brief		Represents a git tree object
	 *
	 */
	class GITWRAP_API ObjectTree : public Object
	{
	public:
		ObjectTree();
		ObjectTree( Internal::ObjectPrivate* _d );
		ObjectTree( const ObjectTree& o );

	public:
		ObjectTree subPath( const QString& pathName, Result& result GITWRAP_DEFAULT_TLSRESULT ) const;

		DiffList diffToTree( ObjectTree newTree, Result& result GITWRAP_DEFAULT_TLSRESULT );
		DiffList diffToIndex( Result& result GITWRAP_DEFAULT_TLSRESULT );
		DiffList diffToWorkingDir( Result& result GITWRAP_DEFAULT_TLSRESULT );

		size_t entryCount() const;
		TreeEntry entryAt( size_t index ) const;
		TreeEntry entry( const QString& fileName ) const;

	public:
		inline TreeEntry operator[]( size_t index ) const
		{
			return entryAt( index );
		}

		inline TreeEntry operator[]( const QString& fileName ) const
		{
			return entry( fileName );
		}
	};

}

Q_DECLARE_METATYPE( Git::ObjectTree )

#endif
