package{
	
	import flash.display.Sprite;
	
	public class AddElementsAttributes extends Sprite{
		private var _book:XML;
		public function AddElementsAttributes(){
		  addElementNode();
		  appendChildElementNode();
		  insertNodeBeforeNode();
		  appendTextNode();
		  appendTextNode2();
		  addAttribute();
		}

		private function addElementNode():void {
	          _book = new XML(<book />);
	          _book.appendChild(<publisher />);
	          trace(_book);
         }

		private function appendChildElementNode():void {
			_book.subject = <subject />;
			trace(_book);
		}

		private function insertNodeBeforeNode():void {
			_book.insertChildBefore(_book.subject, <title />);
			trace(_book);
			//insertChildAfter
		}

		private function appendTextNode():void {
			_book.subject.appendChild("ActionScript");
			trace(_book);
			//prependChild
		}

		private function appendTextNode2():void {
			_book.title = "Learning ActionScript 3.0";
			trace(_book);
		}

		private function addAttribute():void {
			_book.publisher.@name = "O'Reilly";
			trace(_book);
		}
	}
}

