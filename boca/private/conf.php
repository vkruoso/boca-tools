<?php
//////////////////////////////////////////////////////////////////////////////////////////
//BOCA Online Contest Administrator. Copyright (c) 2003-2006 Cassio Polpo de Campos.
//It may be distributed under the terms of the Q Public License version 1.0. A copy of the
//license can be found with this software or at http://www.opensource.org/licenses/qtpl.php
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
//PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER
//OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR
//CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
//PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
//OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
///////////////////////////////////////////////////////////////////////////////////////////
function globalconf() {
  $conf["dblocal"]="false"; // use unix socket to connect?
  $conf["dbhost"]="localhost";
  $conf["dbencoding"]="UTF8";
  $conf["dbclientenc"]="LATIN1";
  $conf["dbname"]=""; // name of the boca database
  $conf["dbport"]="5432";
  $conf["dbuser"]=""; // unprivileged boca user
  $conf["dbpass"]="";

  $conf["dbsuperuser"]=""; // privileged boca user
  $conf["dbsuperpass"]="";

  // note that it is fine to use the same user

  // secret key to be used in HTTP headers
  // you MUST set it with any random large enough sequence
  $conf["key"]="";


  // the following field is used by the autojudging script
  // set it with the ip of the computer running the script
  $conf["ip"]='local';

  return $conf;
}
?>
