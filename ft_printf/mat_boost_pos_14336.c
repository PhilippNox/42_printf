/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_boost_pos_14336.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/27 01:46:41 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*boost14336_part1(void)
{
	return ("637482748729008029258291620423962392339887027287184523335211457951"
	"10065707869381498121644508253319562092051081220601287939836690427327485394"
	"89094174219342618837367169011445304286281749943966280521397450315847509159"
	"78273491886413038211180137911650300957472165189932736576193567077327799907"
	"96997177996578592334407535748207210760036188503212552125558146141639073912"
	"65352487385447207946699860770448090335657572681356156735043357704538811440"
	"10911359401633703869378204313734260255289691781445385162852684463154390899"
	"77971962292355252069691935371206806869744504726222962796403728313406926501"
	"15404242284337658773621145823688513203765295851336078499385947810960419527"
	"89405290595241076622071699639624190503295368268505241656047668548152536367"
	"61007766495495867211444543118747287062377626601354750987726880304415712097"
	"55382660703929069851162755493398922566120405302836337786214275062072832042"
	"38306044288214455495743844579444593235567866508407016159563300855075169104"
	"20359231854367610828767434265997571118708110845242546761897962310103704448"
	"90614605599231591475920022508925259083526847210319975856866720054515526649"
	"49064345032124373792711110885097270145392835039201659011400975901774690266"
	"93143064012261662956756352362310743845819773651825167115949141998299536006"
	"97811555339156164458125115411049474472882533465511833937283040303860112771"
	"77461652609175214004927746950314722020255859572390794841181529721166081363"
	"41050071863736105873153244151600726105422935659950867863647728848790146592"
	"40749560711769142659670433546757289045985658595219471203278792209932312886"
	"02886890856699714997080926956484381197814251121792995771285849408690374991"
	"26500623300300105446543602746390902808779798366519027640882195780245125249"
	"57310132794660416044725417686122536930861830570544910197843248985605531590"
	"010015704134922982755143033204458209358387726124044688138593542684589222");
}

char	*boost14336_part2(void)
{
	return ("848419439516556621293663548241999684208567156923807767553127756836"
	"91648459793629827139335931525024178467319738125838181824170722617060997431"
	"70358453797545176509245518060702601991452689955503139330454754282049751318"
	"92346917978643845680025226696398447131384923212563707734873698531466961639"
	"61104502326077259920086417400034440010935449919634009087736018586349082775"
	"00654746131563923697974529519815542263025662751752969382178189995097143276"
	"12396523632781002410012177738898554790727101000110056696056539363729438509"
	"76629262657819872318026247410714665166022140612475155978587712655710148753"
	"08041350192169874616096316270086441060450981196223866795180680860748142595"
	"24656009952899135020904784283202368181561700961834729991839133288139975584"
	"00263294735102325176864379546505510999250039241986225304874204134321679729"
	"28599795661293331907837256203009737017490124815692349249195575986824152058"
	"83822640283001708835044563816082874905047580136134132275063168518806855849"
	"03537782002248624186133887460286973373951031801204364120120150171974747585"
	"04779299403434573036333177868034243701889490150705729120511436509336303290"
	"72370930589933966729460508097108733644054443723716763907946217164204738814"
	"01123603768524883093507079451810721576914042525815956585648574106548960305"
	"92400954109153816070349926202904950750682468444680854268664941671705919910"
	"31255049285857439524201164795201361473169316840160794042870365507703796876"
	"80471297434215701828041666688456235572276875617880637052987951678439081301"
	"48072322313983109067475394009540531923662422603157507826394749684934955607"
	"94909713100537393315214156443491508213422657367359719791181812661944758452"
	"84940127427767282557083840190821622814249891604656113637869004676965655600"
	"27689741738046929907618775580835055408267000374592014941199756142287923669"
	"093101103350624203850288267284377605010391142335722560012928899788174978");
}

char	*boost14336_part3(void)
{
	return ("756291711610126418279375197645615005250181804577986369008499232804"
	"85626768005774562596989512480447819731592477749587620286846921076635823219"
	"74399554703588590947809312421701318199781380436059835052053540736198272197"
	"05539740899247556773099582472943165074866247049724721375014475204655427462"
	"02056487166244303115463093809536218419482616393234282018539585222689912213"
	"55928865136139721696032314870645417078072797378883423123906168082799974453"
	"22794263428531882122481914413749372939467927462492220285542463734871311802"
	"16220793947537601507057448136138013238218565395581545005940066250307419941"
	"2015616843024827188797064051814398834125010590441863");
}

void	boost14336(t_str_f *input)
{
	char	*(*boost_fun[7])(void);

	boost_fun[0] = &boost14336_part1;
	boost_fun[1] = &boost14336_part2;
	boost_fun[2] = &boost14336_part3;
	boost_fun[3] = NULL;
	boost_fun[4] = NULL;
	boost_fun[5] = NULL;
	boost_fun[6] = NULL;
	boost_pos_do(input, boost_fun);
}
