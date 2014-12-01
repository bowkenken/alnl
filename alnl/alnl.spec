Name: alnl
Version: 4.1.0
Release: 1
Group: Amusements/Games
Distribution: Public Distribution
Vendor: BowKenKen
URL:https://alnl.sourceforge.jp/x/
Packager: BowKenKen <bowkenken@users.sourceforge.jp>
License: GPL
Summary: AL&L - Advanced Labyrinths & Legends - Fantasy RPG
Summary(ja): AL&L - ���ɥХ󥹥ȡ���ӥ�󥹥����쥸���� - �ե��󥿥���RPG
BuildRoot: %{_tmppath}/%{name}-%{version}-root
Source0: %{name}-%{version}.tar.gz
Source1: https://sourceforge.jp/projects/alnl/files/

####

%description
Advanced Labyrinths & Legends is Rogue like RPG of the system such as
Rogue, Moria, NetHack and "Torneko's Great Adventure".
The "Put a party together." thing that it couldn't be done with
Rogue like is made.

%description -l ja
Advanced Labyrinths & Legends �ϡ� Rogue, Moria, NetHack, �ȥ�ͥ��������� 
�ʤɤη����Υ������饤���� RPG �Ǥ���
�����ǤϽ���ʤ��ä��֥ѡ��ƥ����Ȥ�פ��Ȥ�����ޤ���

####

%prep
%setup

####

%build
%configure
make

####

%install
%makeinstall

####

%clean

####

%files
%{_bindir}/%{name}
%{_mandir}/man6/%{name}.6*
%{_mandir}/man6/%{name}-faq.6*

####

%changelog
