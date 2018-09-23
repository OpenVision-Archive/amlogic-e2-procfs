################################################################################
#      This file is part of SIP-Online - http://www.sip-online.fr
#      Copyright (C) 2009-2016 SIP-Online (contact@sip-online.fr)
#
#  OpenELEC is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 2 of the License, or
#  (at your option) any later version.
#
#  OpenELEC is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with OpenELEC.  If not, see <http://www.gnu.org/licenses/>.
################################################################################

PKG_NAME="amlogic-e2-procfs"
PKG_VERSION="3.14.29"
PKG_REV="1"
PKG_ARCH="arm"
PKG_LICENSE="nonfree"
PKG_SITE="https://github.com/PLi-metas"
PKG_URL=""
PKG_DEPENDS_TARGET="toolchain linux"
PKG_NEED_UNPACK="$LINUX_DEPENDS"
PKG_PRIORITY="optional"
PKG_SECTION="driver"
PKG_SHORTDESC="Amlogic Enigma2 procfs drivers"
PKG_LONGDESC="These package contains Amlogic's PROCFS driver"
PKG_MAINTAINER="Persian Prince (persianpros@yahoo.com)"

PKG_IS_ADDON="no"
PKG_AUTORECONF="no"

pre_make_target() {
	unset LDFLAGS
}

make_target() {
	if [ -d "$ROOT/$BUILD" ]; then
		if [ -d "$ROOT/$PKG_BUILD" ]; then
			rm -rf "$ROOT/$PKG_BUILD"
		fi

		cp -rf "$PKG_DIR/source" "$ROOT/$PKG_BUILD"
	fi

	cd "$ROOT/$PKG_BUILD/e2_procfs"

	make \
		V=1 \
		ARCH=$TARGET_ARCH \
		KSRC=$(kernel_path) \
		CROSS_COMPILE=$TARGET_PREFIX

	fix_module_depends "e2_procfs.ko" "wetekdvb"
}

makeinstall_target() {
	mkdir -p "$INSTALL/lib/modules/$(get_module_dir)/$PKG_NAME"
	install -m 0755 *.ko "$INSTALL/lib/modules/$(get_module_dir)/$PKG_NAME"
}
