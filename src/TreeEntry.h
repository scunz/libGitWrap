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

#ifndef GIT_TREE_ENTRY_H
#define GIT_TREE_ENTRY_H

#include "Git.h"

namespace Git
{

	class ObjectId;
	class TreeEntryPrivate;

	class GITWRAP_API TreeEntry
	{
	public:
		TreeEntry();
		TreeEntry( TreeEntryPrivate* _d );
		TreeEntry( const TreeEntry& other );
		~TreeEntry();
		TreeEntry& operator=( const TreeEntry& other );

	public:
		bool isValid() const;

		TreeEntry clone() const;

		ObjectId sha1() const;
		QString name() const;
		ObjectType type() const;

	private:
		GitPtr< TreeEntryPrivate > d;
	};

}

#endif