package {

	import flash.display.Sprite;

	public class CreateXML extends Sprite {
		
		private var _authors:XML;
		private var _author1:String;
		private var _author2:String;
		private var _book:XML;
		private var _bookStr:String;
		private var _publisher:String;
		
		public function CreateXML() {

			_author1 = "Rosser";
			_author2  = "Shupe";
			_publisher  = "O'Reilly";

			fromNodes();
			nodesWithVariables();
			fromString();
			stringWithVariables();
		}
		private function fromNodes() {
			_authors =<authors>
			<author>
			<firstname>Rich</firstname>
			                     <lastname>Shupe</lastname>
			</author>
			<author>
			<firstname>Zevan</firstname>
			                     <lastname>Rosser</lastname>
			</author>
			</authors>;
			trace(_authors);
		}
		private function nodesWithVariables() {
			_authors = <authors>
			<author>
			<firstname>{_author1}</firstname>
			                     <lastname>{_author2}</lastname>
			</author>
			</authors>;
			trace(_authors);
		}
		private function fromString() {
			_bookStr = "<book><publisher>O'Reilly</publisher></book>";
			_book = new XML(_bookStr);
			trace(_book);
		}
		private function stringWithVariables() {
			_bookStr = "<book><publisher>" + _publisher + "</publisher></book>";
			_book = new XML(_bookStr);
			trace(_book);
		}
	}
}