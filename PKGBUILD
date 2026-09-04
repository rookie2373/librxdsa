# Maintainer: Rushikesh Kundkar <rrkundkar777@gmail.com>
pkgname=librxdsa
pkgver=0.0.20
pkgrel=1
pkgdesc="Standalone and lightweight C algorithms library"
arch=('x86_64' 'aarch64')
url="https://github.com/rookie2373/${pkgname}"
license=('GPL-3.0')
depends=('glibc')
source=("librxdsa-${pkgver}.tar.gz::${url}/releases/download/${pkgver}/librxdsa-${pkgver}.tar.gz")
sha256sums=('SKIP')

build() {
    cd "librxdsa-${pkgver}"
    make lib
}

package() {
    cd "librxdsa-${pkgver}"
    make DESTDIR="${pkgdir}" PREFIX=/usr install
    install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}