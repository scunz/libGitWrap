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

#ifndef GIT_REMOTE_H
#define GIT_REMOTE_H

#include "GitWrap.h"

namespace Git
{

	namespace Internal
	{
		class RemotePrivate;
	}

	class ObjectId;
	class Reference;
	class RefSpec;

	/**
	 * @ingroup		GitWrap
	 * @brief		Represents a git remote.
	 *
	 * Remotes are used to synchronize with foreign repositories, which may actually be on the local
	 * or on a remote site.
	 *
	 */
	class GITWRAP_API Remote
	{
	public:
		Remote();
		Remote( Internal::RemotePrivate* _d );
		Remote( const Remote& other );
		~Remote();
		Remote& operator=( const Remote& other );

	public:
		bool isValid() const;

		bool save( Result& result GITWRAP_DEFAULT_TLSRESULT );

		QString name() const;
		QString url() const;

		bool setFetchSpec( const QString& spec, Result& result GITWRAP_DEFAULT_TLSRESULT );
		bool setPushSpec( const QString& spec, Result& result GITWRAP_DEFAULT_TLSRESULT );

		RefSpec fetchSpec() const;
		RefSpec pushSpec() const;

		static bool isValidUrl( const QString& url );
		static bool isSupportedUrl( const QString& url );

		bool connect( bool forFetch, Result& result GITWRAP_DEFAULT_TLSRESULT );
		void disconnect( Result& result GITWRAP_DEFAULT_TLSRESULT );
		bool download( Result& result GITWRAP_DEFAULT_TLSRESULT );
		bool updateTips( Result& result GITWRAP_DEFAULT_TLSRESULT );

	private:
		Internal::GitPtr< Internal::RemotePrivate > d;
	};

}

Q_DECLARE_METATYPE( Git::Remote )

#endif
